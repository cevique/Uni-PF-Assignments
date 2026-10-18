 {
        srand(time(NULL)); //seeded rng 

            //random x positions for everything 
        int Px = rand() % 20, Py = rand() % 10; //packmax x,y position
        int Cx = rand() % 20, Cy = rand() % 10; //clyde x,y position
        int Ix = rand() % 20, Iy = rand() % 10; //Inky x,y position
        int Pix = rand() % 20, Piy = rand() % 10; //pinky x,y position

        // Blinky (y=2 , y =7 )
        int start_B = rand() % 40; // <20 spawn top y=2 , >20 spawn bot y=7
        int B_state = (start_B < 20) ? 0 : 1; // 0: Top moving right, 1: Bottom moving left
        int Bx = (start_B < 20) ? start_B : (start_B - 20);
        int By = (B_state == 0) ? 2 : 7;

        int game_state = 0; // 0 = Playing, 1 = Win, 2 = Loss

        while (game_state == 0) {
     
            for (int i = 0; i < 40; i++) cout << '\n';
            this_thread::sleep_for(chrono::milliseconds(20));

            cout << "PAC-A-MAN!\n";
            cout << "Controls: W A S D + Enter\n\n";
            cout << "ps I actually dont think this is winnable." << endl;

            // board
            for (int y = 0; y < 10; y++) {
                for (int x = 0; x < 20; x++) {
                    char cell = '*'; 

                    // Overlap display priority
                    cell = (x == Cx && y == Cy) ? 'C' : cell;
                    cell = (x == Ix && y == Iy) ? 'I' : cell;
                    cell = (x == Pix && y == Piy) ? 'P' : cell;
                    cell = (x == Bx && y == By) ? 'B' : cell;
                    cell = (x == Px && y == Py) ? '@' : cell;

                    cout << cell << ' ';
                }
                cout << '\n';
            }

            // PC input and mvmnt
            char input;
            cout << "\nMove: ";
            cin >> input;

            int old_Px = Px;
            int old_Py = Py;

            //movement
            switch (input) {
            case 'w': case 'W': Py--; break;
            case 's': case 'S': Py++; break;
            case 'a': case 'A': Px--; break;
            case 'd': case 'D': Px++; break;
            default: break;
            }

            //boundry rules
            Px = (Px < 0) ? 0 : ((Px > 19) ? 19 : Px); //throws the man back into the game if he wanders off screen
            Py = (Py < 0) ? 0 : ((Py > 9) ? 9 : Py);

            // Clyde logics
            //move like the man
            int pac_dx = Px - old_Px;
            int pac_dy = Py - old_Py;
            Cx += pac_dx;
            Cy += pac_dy;

            Cx = (Cx < 0) ? 0 : ((Cx > 19) ? 19 : Cx);
            Cy = (Cy < 0) ? 0 : ((Cy > 9) ? 9 : Cy);

            //wincheck
            game_state = (Px == Cx && Py == Cy) ? 1 : game_state;


            // Inky's logics
            // Calculate Euclidean distance
            long long dC = (Cx - Px) * (Cx - Px) + (Cy - Py) * (Cy - Py);  //using distance formula in a cartesian plane
            long long dI = (Ix - Px) * (Ix - Px) + (Iy - Py) * (Iy - Py);
            long long dP = (Pix - Px) * (Pix - Px) + (Piy - Py) * (Piy - Py);
            long long dB = (Bx - Px) * (Bx - Px) + (By - Py) * (By - Py);

            bool inky_closest = (dI <= dC) && (dI <= dP) && (dI <= dB);

            // Check clockwise free spaces on top right bottom and left.
            bool free_top = (Py - 1 >= 0) && !(Px == Cx && Py - 1 == Cy) && !(Px == Pix && Py - 1 == Piy) && !(Px == Bx && Py - 1 == By) && !(Px == Px && Py - 1 == Py); 
            bool free_rgt = (Px + 1 <= 19) && !(Px + 1 == Cx && Py == Cy) && !(Px + 1 == Pix && Py == Piy) && !(Px + 1 == Bx && Py == By) && !(Px + 1 == Px && Py == Py);
            bool free_bot = (Py + 1 <= 9) && !(Px == Cx && Py + 1 == Cy) && !(Px == Pix && Py + 1 == Piy) && !(Px == Bx && Py + 1 == By) && !(Px == Px && Py + 1 == Py);
            bool free_lft = (Px - 1 >= 0) && !(Px - 1 == Cx && Py == Cy) && !(Px - 1 == Pix && Py == Piy) && !(Px - 1 == Bx && Py == By) && !(Px - 1 == Px && Py == Py);

            int new_Ix = inky_closest ? (free_top ? Px : (free_rgt ? Px + 1 : (free_bot ? Px : (free_lft ? Px - 1 : Ix)))) : Ix;
            int new_Iy = inky_closest ? (free_top ? Py - 1 : (free_rgt ? Py : (free_bot ? Py + 1 : (free_lft ? Py : Iy)))) : Iy;

            // update if not won by clyde?
            Ix = (game_state == 0) ? new_Ix : Ix;
            Iy = (game_state == 0) ? new_Iy : Iy;

            //Inky losscheck
            game_state = (game_state == 0 && Px == Ix && Py == Iy) ? 2 : game_state;


            //Pinky logics
            // Moves one unit based on the largest distance to Pac-Man, or diagonal on a tie
            int pinky_dx = Px - Pix;
            int pinky_dy = Py - Piy;
            int abs_pdx = (pinky_dx < 0) ? -pinky_dx : pinky_dx;
            int abs_pdy = (pinky_dy < 0) ? -pinky_dy : pinky_dy;

            int sx = (pinky_dx > 0) ? 1 : ((pinky_dx < 0) ? -1 : 0);
            int sy = (pinky_dy > 0) ? 1 : ((pinky_dy < 0) ? -1 : 0);

            int new_Pix = Pix + ((abs_pdx > abs_pdy) ? sx : ((abs_pdx == abs_pdy) ? sx : 0));
            int new_Piy = Piy + ((abs_pdy > abs_pdx) ? sy : ((abs_pdx == abs_pdy) ? sy : 0));

            Pix = (game_state == 0) ? new_Pix : Pix;
            Piy = (game_state == 0) ? new_Piy : Piy;

            //Pinky losscheck
            game_state = (game_state == 0 && Px == Pix && Py == Piy) ? 2 : game_state;


            //Blinky logics
            // traverse lines and teleport
            int new_Bx = Bx + ((B_state == 0) ? 1 : -1);
            bool top_end = (B_state == 0 && new_Bx > 19);
            bool bot_end = (B_state == 1 && new_Bx < 0);

            B_state = top_end ? 1 : (bot_end ? 0 : B_state);
            new_Bx = top_end ? 19 : (bot_end ? 0 : new_Bx);
            int new_By = top_end ? 7 : (bot_end ? 2 : By);

            Bx = (game_state == 0) ? new_Bx : Bx;
            By = (game_state == 0) ? new_By : By;

            //binky loss check
            game_state = (game_state == 0 && Px == Bx && Py == By) ? 2 : game_state;
        }

        for (int i = 0; i < 40; i++) cout << '\n';

        for (int y = 0; y < 10; y++) {
            for (int x = 0; x < 20; x++) {
                char cell = '*';
                cell = (x == Cx && y == Cy) ? 'C' : cell;
                cell = (x == Ix && y == Iy) ? 'I' : cell;
                cell = (x == Pix && y == Piy) ? 'P' : cell;
                cell = (x == Bx && y == By) ? 'B' : cell;
                cell = (x == Px && y == Py) ? '@' : cell;
                cout << cell << ' ';
            }
            cout << '\n';
        }
        //outputs
        switch (game_state) {
        case 1:
            cout << "\nSiren activated , you win.\n";
            break;
        case 2:
            cout << "\nGame over gg.\n";
            break;
    }
      