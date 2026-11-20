#include <iostream>
#include "terminal.h"

using namespace std;

int slotFor(int world_base, int col)
{
    return (world_base + col) % 114;
}

int rockWidth(int kind)
{
    return (kind == 1) ? 6 : 8;
}

int rockHeight(int kind)
{
    return (kind == 1) ? 2 : 4;
}

char birdGlyph(int facing_right, int wing_state, int row, int col)
{
    const char upRight[2][11] = {"   |\\", "~==|_ \\o=>"};
    const char downRight[2][11] = {"~==|-/o=>", "    |/"};
    const char upLeft[2][11] = {"   /|", "<=o/_|==~"};
    const char downLeft[2][11] = {"<=o|-\\==~", "   \\|"};
    if (facing_right == 1)
    {
        if (wing_state == 0)
        {
            return upRight[row][col];
        }
        return downRight[row][col];
    }
    if (wing_state == 0)
    {
        return upLeft[row][col];
    }
    return downLeft[row][col];
}

char rockGlyph(int kind, int row, int col)
{
    const char smallRock[2][8] = {" .---.", "(#####)"};
    const char largeRock[4][9] = {"  ___   ", " _/##\\_ ", "(######)", " `----' "};
    if (kind == 1)
    {
        return smallRock[row][col];
    }
    if (kind == 2)
    {
        return largeRock[row][col];
    }
    return ' ';
}

void formatFive(int value, char buf[])
{
    buf[5] = '\0';
    for (int i = 4; i >= 0; --i)
    {
        buf[i] = (value % 10) + '0';
        value = value / 10;
    }
}

void resetWorld(int cave_center[], int cave_gap[], int &world_base, int &bird_row, int &facing_right,
                int &distance, int &game_state, int &frame_num, int &corridor_kind, int &corridor_dir,
                int &corridor_left, int &pending_kind, int &pending_top, int &pending_index, int &rock_count)
{
    bird_row = 14;
    facing_right = 1;
    distance = 0;
    game_state = 0;
    frame_num = 0;
    world_base = 0;
    corridor_kind = 0;
    corridor_dir = 0;
    corridor_left = 10;
    pending_kind = 0;
    pending_top = 0;
    pending_index = -1;
    rock_count = 0;
    for (int i = 0; i < 114; ++i)
    {
        cave_center[i] = 15;
        cave_gap[i] = 20;
    }
}

void moveRocks(int rock_kind[], int rock_top[], int rock_anchor[], int rock_lo[], int rock_hi[],
               int rock_flip[], int &rock_count, int facing_right, int &pending_index)
{
    int step = (facing_right == 1) ? -1 : 1;
    int i = 0;
    while (i < rock_count)
    {
        rock_anchor[i] = rock_anchor[i] + step;
        if (rock_flip[i] == 0)
        {
            while (rock_hi[i] >= rock_lo[i] and rock_anchor[i] + rock_hi[i] > 113)
            {
                rock_hi[i] = rock_hi[i] - 1;
            }
            while (rock_lo[i] <= rock_hi[i] and rock_anchor[i] + rock_lo[i] < 0)
            {
                rock_lo[i] = rock_lo[i] + 1;
            }
        }
        else
        {
            while (rock_hi[i] >= rock_lo[i] and rock_anchor[i] - rock_hi[i] < 0)
            {
                rock_hi[i] = rock_hi[i] - 1;
            }
            while (rock_lo[i] <= rock_hi[i] and rock_anchor[i] - rock_lo[i] > 113)
            {
                rock_lo[i] = rock_lo[i] + 1;
            }
        }
        if (rock_lo[i] > rock_hi[i])
        {
            int last = rock_count - 1;
            if (pending_index == last)
            {
                pending_index = i;
            }
            rock_kind[i] = rock_kind[last];
            rock_top[i] = rock_top[last];
            rock_anchor[i] = rock_anchor[last];
            rock_lo[i] = rock_lo[last];
            rock_hi[i] = rock_hi[last];
            rock_flip[i] = rock_flip[last];
            rock_count = last;
            if (pending_index >= rock_count)
            {
                pending_index = -1;
            }
        }
        else
        {
            i = i + 1;
        }
    }
}

void generateColumn(int cave_center[], int cave_gap[], int world_base, int new_col, int source_col,
                    int facing_right, int distance, int &corridor_kind, int &corridor_dir, int &corridor_left,
                    int &pending_kind, int &pending_top, int &pending_index,
                    int rock_kind[], int rock_top[], int rock_anchor[], int rock_lo[], int rock_hi[],
                    int rock_flip[], int &rock_count)
{
    int source_slot = slotFor(world_base, source_col);
    int new_slot = slotFor(world_base, new_col);
    int old_top = cave_center[source_slot] - cave_gap[source_slot] / 2;
    int old_bottom = old_top + cave_gap[source_slot];

    if (corridor_left <= 0)
    {
        int level = distance / 250;
        int rock_chance = 35 + 5 * level;
        if (rock_chance > 70)
        {
            rock_chance = 70;
        }
        if (distance >= 150 and randomInt(0, 99) < rock_chance)
        {
            corridor_kind = 1;
            corridor_left = 28;
            pending_kind = randomInt(0, 1) + 1;
            int height = rockHeight(pending_kind);
            int top_bound = old_top + 1;
            int bot_bound = old_bottom - 1 - height;
            pending_top = top_bound;
            if (top_bound <= bot_bound)
            {
                pending_top = randomInt(top_bound, bot_bound);
            }
            if (pending_top - old_top < 4 or old_bottom - (pending_top + height) < 4)
            {
                pending_top = old_top + 1;
            }
            pending_index = -1;
        }
        else
        {
            corridor_kind = 0;
            corridor_dir = randomInt(-1, 1);
            corridor_left = randomInt(6, 25);
        }
    }

    if (corridor_kind == 1)
    {
        cave_center[new_slot] = cave_center[source_slot];
        cave_gap[new_slot] = cave_gap[source_slot];
        int wave = 28 - corridor_left;
        int width = rockWidth(pending_kind);
        int rock_start = (28 - width) / 2;
        if (wave >= rock_start and wave < rock_start + width)
        {
            if (wave == rock_start)
            {
                if (rock_count < 128)
                {
                    rock_kind[rock_count] = pending_kind;
                    rock_top[rock_count] = pending_top;
                    rock_anchor[rock_count] = new_col;
                    rock_lo[rock_count] = 0;
                    rock_hi[rock_count] = 0;
                    rock_flip[rock_count] = (facing_right == 1) ? 0 : 1;
                    pending_index = rock_count;
                    rock_count = rock_count + 1;
                }
            }
            else
            {
                if (pending_index >= 0 and pending_index < rock_count and rock_hi[pending_index] < width - 1)
                {
                    rock_hi[pending_index] = rock_hi[pending_index] + 1;
                }
            }
        }
        corridor_left = corridor_left - 1;
    }
    else
    {
        int gap = cave_gap[source_slot];
        int centre = cave_center[source_slot] + corridor_dir;
        int roll = randomInt(0, 99);
        if (roll <= 7)
        {
            gap = gap + 1;
        }
        else
        {
            if (roll <= 15)
            {
                gap = gap - 1;
            }
        }
        int min_gap = 18 - distance / 250;
        if (min_gap < 9)
        {
            min_gap = 9;
        }
        if (gap < min_gap)
        {
            gap = min_gap;
        }
        if (gap > min_gap + 4)
        {
            gap = min_gap + 4;
        }
        int top = centre - gap / 2;
        if (top < 1)
        {
            top = 1;
            corridor_dir = 0;
        }
        if (top + gap > 29)
        {
            top = 29 - gap;
            corridor_dir = 0;
        }
        cave_center[new_slot] = top + gap / 2;
        cave_gap[new_slot] = gap;
        corridor_left = corridor_left - 1;
    }
}

void scrollWorld(int cave_center[], int cave_gap[], int &world_base, int facing_right, int distance,
                 int rock_kind[], int rock_top[], int rock_anchor[], int rock_lo[], int rock_hi[],
                 int rock_flip[], int &rock_count, int &corridor_kind, int &corridor_dir, int &corridor_left,
                 int &pending_kind, int &pending_top, int &pending_index)
{
    moveRocks(rock_kind, rock_top, rock_anchor, rock_lo, rock_hi, rock_flip, rock_count, facing_right, pending_index);
    if (facing_right == 1)
    {
        world_base = (world_base + 1) % 114;
        generateColumn(cave_center, cave_gap, world_base, 113, 112, facing_right, distance,
                       corridor_kind, corridor_dir, corridor_left, pending_kind, pending_top, pending_index,
                       rock_kind, rock_top, rock_anchor, rock_lo, rock_hi, rock_flip, rock_count);
    }
    else
    {
        world_base = (world_base + 113) % 114;
        generateColumn(cave_center, cave_gap, world_base, 0, 1, facing_right, distance,
                       corridor_kind, corridor_dir, corridor_left, pending_kind, pending_top, pending_index,
                       rock_kind, rock_top, rock_anchor, rock_lo, rock_hi, rock_flip, rock_count);
    }
}

bool solidAt(const int cave_center[], const int cave_gap[], int world_base,
             const int rock_kind[], const int rock_top[], const int rock_anchor[], const int rock_lo[],
             const int rock_hi[], const int rock_flip[], int rock_count, int row, int col)
{
    if (row < 0 or row > 29 or col < 0 or col > 113)
    {
        return true;
    }
    int slot = slotFor(world_base, col);
    int top = cave_center[slot] - cave_gap[slot] / 2;
    int bottom = top + cave_gap[slot];
    if (row <= top or row >= bottom)
    {
        return true;
    }
    for (int i = 0; i < rock_count; ++i)
    {
        int art_col;
        if (rock_flip[i] == 0)
        {
            art_col = col - rock_anchor[i];
        }
        else
        {
            art_col = rock_anchor[i] - col;
        }
        if (art_col < rock_lo[i] or art_col > rock_hi[i])
        {
            continue;
        }
        int kind = rock_kind[i];
        int height = rockHeight(kind);
        if (row >= rock_top[i] and row < rock_top[i] + height)
        {
            char ch = rockGlyph(kind, row - rock_top[i], art_col);
            if (ch != ' ')
            {
                return true;
            }
        }
    }
    return false;
}

bool checkCrash(const int cave_center[], const int cave_gap[], int world_base,
                const int rock_kind[], const int rock_top[], const int rock_anchor[], const int rock_lo[],
                const int rock_hi[], const int rock_flip[], int rock_count, int bird_row, int facing_right,
                int wing_state)
{
    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 10; ++c)
        {
            char ch = birdGlyph(facing_right, wing_state, r, c);
            if (ch == ' ' or ch == '\0')
            {
                continue;
            }
            if (solidAt(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor,
                        rock_lo, rock_hi, rock_flip, rock_count, bird_row + r, 53 + c))
            {
                return true;
            }
        }
    }
    return false;
}

void drawWorld(const int cave_center[], const int cave_gap[], int world_base,
               const int rock_kind[], const int rock_top[], const int rock_anchor[], const int rock_lo[],
               const int rock_hi[], const int rock_flip[], int rock_count, int bird_row, int facing_right,
               int wing_state, int distance, int best_dist, int game_state)
{
    cursorHome();

    char grid[30][114];

    for (int col = 0; col < 114; ++col)
    {
        int slot = slotFor(world_base, col);
        int top = cave_center[slot] - cave_gap[slot] / 2;
        int bottom = top + cave_gap[slot];
        for (int row = 0; row < 30; ++row)
        {
            if (row <= top or row >= bottom)
            {
                grid[row][col] = '#';
            }
            else
            {
                grid[row][col] = ' ';
            }
        }
    }

    for (int i = 0; i < rock_count; ++i)
    {
        int kind = rock_kind[i];
        int height = rockHeight(kind);
        for (int a = rock_lo[i]; a <= rock_hi[i]; ++a)
        {
            int col;
            if (rock_flip[i] == 0)
            {
                col = rock_anchor[i] + a;
            }
            else
            {
                col = rock_anchor[i] - a;
            }
            if (col < 0 or col > 113)
            {
                continue;
            }
            for (int r = 0; r < height; ++r)
            {
                int row = rock_top[i] + r;
                if (row < 0 or row > 29)
                {
                    continue;
                }
                char ch = rockGlyph(kind, r, a);
                if (ch != ' ')
                {
                    grid[row][col] = ch;
                }
            }
        }
    }

    for (int r = 0; r < 2; ++r)
    {
        for (int c = 0; c < 10; ++c)
        {
            char ch = birdGlyph(facing_right, wing_state, r, c);
            if (ch == ' ' or ch == '\0')
            {
                continue;
            }
            int row = bird_row + r;
            int col = 53 + c;
            if (row >= 0 and row <= 29 and col >= 0 and col <= 113)
            {
                grid[row][col] = ch;
            }
        }
    }

    char edge[117];
    for (int x = 0; x < 116; ++x)
    {
        edge[x] = '-';
    }
    edge[0] = '+';
    edge[115] = '+';
    edge[116] = '\0';

    char line[117];
    line[0] = '|';
    line[115] = '|';
    line[116] = '\0';

    cout << edge << "\n";
    for (int row = 0; row < 30; ++row)
    {
        for (int col = 0; col < 114; ++col)
        {
            line[col + 1] = grid[row][col];
        }
        cout << line << "\n";
    }
    cout << edge << "\n";

    char dist_buf[6];
    char best_buf[6];
    formatFive(distance, dist_buf);
    formatFive(best_dist, best_buf);

    int wait_ms = 70 - distance / 40;
    if (wait_ms < 30)
    {
        wait_ms = 30;
    }
    int drop_ms = 70 - wait_ms;
    int gt_count = drop_ms / 4;
    if (gt_count > 10)
    {
        gt_count = 10;
    }

    cout << "DIST " << dist_buf << " BEST " << best_buf << " SPEED ";
    for (int i = 0; i < 10; ++i)
    {
        if (i < gt_count)
        {
            cout << '>';
        }
        else
        {
            cout << '-';
        }
    }
    cout << " FLYING ";
    if (facing_right == 1)
    {
        cout << ">>";
    }
    else
    {
        cout << "<<";
    }
    cout << "       \n";

    if (game_state == 0)
    {
        cout << "\r[PTERO] fly the cave. touch nothing. press any key to start.      \n";
    }
    else
    {
        if (game_state == 2)
        {
            cout << "\rSPLATTERED: distance " << distance << " best " << best_dist << " [r] fly again [q] quit\n";
        }
    }
}

int main()
{
    termInit();

    int cave_center[114];
    int cave_gap[114];

    int rock_kind[128] = {0};
    int rock_top[128] = {0};
    int rock_anchor[128] = {0};
    int rock_lo[128] = {0};
    int rock_hi[128] = {0};
    int rock_flip[128] = {0};
    int rock_count = 0;

    int world_base = 0;
    int corridor_kind = 0;
    int corridor_dir = 0;
    int corridor_left = 0;
    int pending_kind = 0;
    int pending_top = 0;
    int pending_index = -1;

    int bird_row = 14;
    int facing_right = 1;
    int distance = 0;
    int best_dist = 0;
    int game_state = 0;
    int frame_num = 0;

    resetWorld(cave_center, cave_gap, world_base, bird_row, facing_right, distance, game_state,
               frame_num, corridor_kind, corridor_dir, corridor_left, pending_kind, pending_top,
               pending_index, rock_count);

    while (true)
    {
        if (game_state == 0)
        {
            int wing_state = (frame_num / 3) % 2;
            drawWorld(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                      rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state, distance, best_dist, game_state);
            if (keyPressed())
            {
                int key = readKey();
                if (key == 'q' or key == 'Q')
                {
                    termRestore();
                    return 0;
                }
                game_state = 1;
            }
            sleepMs(50);
            frame_num = frame_num + 1;
            continue;
        }

        if (game_state == 1)
        {
            while (keyPressed())
            {
                int key = readKey();
                if (key == 'q' or key == 'Q')
                {
                    termRestore();
                    return 0;
                }
                if (key == 'w' or key == 'W' or key == KEY_ARROW_UP)
                {
                    if (bird_row > 0)
                    {
                        bird_row = bird_row - 1;
                    }
                }
                if (key == 's' or key == 'S' or key == KEY_ARROW_DOWN)
                {
                    if (bird_row < 28)
                    {
                        bird_row = bird_row + 1;
                    }
                }
                if (key == 'a' or key == 'A' or key == KEY_ARROW_LEFT)
                {
                    if (facing_right == 1)
                    {
                        facing_right = 0;
                        corridor_kind = 0;
                        corridor_dir = 0;
                        corridor_left = 10;
                        pending_kind = 0;
                        pending_index = -1;
                    }
                }
                if (key == 'd' or key == 'D' or key == KEY_ARROW_RIGHT)
                {
                    if (facing_right == 0)
                    {
                        facing_right = 1;
                        corridor_kind = 0;
                        corridor_dir = 0;
                        corridor_left = 10;
                        pending_kind = 0;
                        pending_index = -1;
                    }
                }
            }

            distance = distance + 1;
            if (distance > best_dist)
            {
                best_dist = distance;
            }

            scrollWorld(cave_center, cave_gap, world_base, facing_right, distance, rock_kind, rock_top,
                        rock_anchor, rock_lo, rock_hi, rock_flip, rock_count, corridor_kind, corridor_dir,
                        corridor_left, pending_kind, pending_top, pending_index);

            int wing_state = (frame_num / 3) % 2;
            if (checkCrash(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                           rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state))
            {
                game_state = 2;
                flushKeys();
            }

            drawWorld(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                      rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state, distance, best_dist, game_state);

            int wait_ms = 70 - distance / 40;
            if (wait_ms < 30)
            {
                wait_ms = 30;
            }
            sleepMs(wait_ms);
            frame_num = frame_num + 1;
        }
        else
        {
            if (game_state == 2)
            {
                int wing_state = (frame_num / 3) % 2;
                drawWorld(cave_center, cave_gap, world_base, rock_kind, rock_top, rock_anchor, rock_lo,
                          rock_hi, rock_flip, rock_count, bird_row, facing_right, wing_state, distance, best_dist, game_state);
                if (keyPressed())
                {
                    int key = readKey();
                    if (key == 'q' or key == 'Q')
                    {
                        termRestore();
                        return 0;
                    }
                    if (key == 'r' or key == 'R' or key == ' ')
                    {
                        resetWorld(cave_center, cave_gap, world_base, bird_row, facing_right, distance,
                                   game_state, frame_num, corridor_kind, corridor_dir, corridor_left,
                                   pending_kind, pending_top, pending_index, rock_count);
                        game_state = 1;
                    }
                }
                sleepMs(50);
            }
        }
    }

    termRestore();
    return 0;
}
