#include <iostream>
#include "helperCells.h"
typedef long long LongLong;
using namespace std;

const int MAX_ROWS = 51, MAX_COLS = 26, VISIBLE_ROWS = 27, SCREEN_WIDTH = 116, MAX_STRING_SIZE = 2048;
const int t_empty = 0, t_num = 1, t_str = 2, t_err = 3, t_range = 4;

char raw_cells[MAX_ROWS][MAX_COLS][64], display_cells[MAX_ROWS][MAX_COLS][MAX_STRING_SIZE], cell_strings[MAX_ROWS][MAX_COLS][MAX_STRING_SIZE];
double cell_numbers[MAX_ROWS][MAX_COLS];
int cell_types[MAX_ROWS][MAX_COLS], visit_state[MAX_ROWS][MAX_COLS], column_widths[MAX_COLS];

// parser state
int token_types[80], token_rows[80], token_columns[80], token_count, token_position;
double token_values[80];
char token_strings[80][MAX_STRING_SIZE];
bool syntax_error;

// string helpers
int stringLength(const char s[]) {
    int length = 0;
    while (s[length] != '\0') length++;
    return length;
}

void stringCopy(char d[], const char s[]) {
    int i = 0;
    while (s[i] != '\0' && i < MAX_STRING_SIZE - 1) { d[i] = s[i]; i++; }
    d[i] = '\0';
}

void stringConcat(char d[], const char s[]) {
    int i = stringLength(d), j = 0;
    while (s[j] != '\0' && i < MAX_STRING_SIZE - 1) d[i++] = s[j++];
    d[i] = '\0';
}

void appendCharacter(char d[], char c) {
    int i = stringLength(d);
    d[i] = i < MAX_STRING_SIZE - 1 ? c : '\0';
    d[i < MAX_STRING_SIZE - 1 ? i + 1 : i] = '\0';
}

int stringCompare(const char a[], const char b[]) {
    int i = 0;
    while (a[i] != '\0' && a[i] == b[i]) i++;
    return (unsigned char)a[i] - (unsigned char)b[i];
}

void toUpperCase(char s[]) {
    for (int i = 0; s[i] != '\0'; i++)
        s[i] = (s[i] >= 'a' && s[i] <= 'z') ? char(s[i] - 32) : s[i];
}

void longLongToString(LongLong input_value, char screen_buffer[]) {
    int i = 0;
    bool is_negative = input_value < 0;
    LongLong current_value = is_negative ? -input_value : input_value;
    screen_buffer[i] = current_value == 0 ? '0' : '\0';
    i += current_value == 0 ? 1 : 0;
    while (current_value > 0) { screen_buffer[i++] = char('0' + (current_value % 10)); current_value /= 10; }
    screen_buffer[i] = is_negative ? '-' : '\0';
    i += is_negative ? 1 : 0;
    screen_buffer[i] = '\0';
    for (int l = 0, r = i - 1; l < r; l++, r--) {
        char temporary = screen_buffer[l]; screen_buffer[l] = screen_buffer[r]; screen_buffer[r] = temporary;
    }
}

void getCellAddress(int r, int c, char screen_buffer[]) {
    screen_buffer[0] = char('A' + c);
    longLongToString(r, screen_buffer + 1);
}

// math helpers
double doubleAbs(double input_value) {
    return input_value < 0.0 ? -input_value : input_value;
}

double doubleFloor(double input_value) {
    if (input_value >= 9e18 || input_value <= -9e18) return input_value;
    LongLong i = (LongLong)input_value;
    double d = (double)i;
    return (input_value < 0.0 && d != input_value) ? d - 1.0 : d;
}

double roundDecimal(double input_value, int decimal_places) {
    if (doubleAbs(input_value) >= 1e15) return input_value;
    bool is_negative = input_value < 0.0;
    double absolute_value = is_negative ? -input_value : input_value, power = 1.0;
    for (int i = 0; i < decimal_places; i++) power *= 10.0;
    LongLong integer_part = (LongLong)absolute_value;
    double fractional_part = absolute_value - (double)integer_part;
    LongLong fractional_remainder = (LongLong)(fractional_part * power + 0.5 + 1e-9), left_padding = (LongLong)power;
    integer_part += fractional_remainder >= left_padding ? 1 : 0;
    fractional_remainder -= fractional_remainder >= left_padding ? left_padding : 0;
    double result = (double)integer_part + (double)fractional_remainder / power;
    return is_negative ? -result : result;
}

double calculateSquareRoot(double input_value) {
    if (input_value <= 0.0) return 0.0;
    double r = input_value > 1.0 ? input_value : 1.0;
    for (int i = 0; i < 64; i++) r = 0.5 * (r + input_value / r);
    return r;
}

void formatNumber(double input_value, char screen_buffer[]) {
    if (input_value != input_value || doubleAbs(input_value) >= 1e15) { stringCopy(screen_buffer, "#NUM!"); return; }
    bool is_negative = input_value < 0.0;
    double absolute_value = is_negative ? -input_value : input_value;
    LongLong integer_part = (LongLong)absolute_value;
    LongLong fractional_remainder = (LongLong)((absolute_value - (double)integer_part) * 10000.0 + 0.5 + 1e-9);
    integer_part += fractional_remainder >= 10000 ? 1 : 0;
    fractional_remainder -= fractional_remainder >= 10000 ? 10000 : 0;
    if (integer_part >= 1000000000000000LL) { stringCopy(screen_buffer, "#NUM!"); return; }
    if (integer_part == 0 && fractional_remainder == 0) { stringCopy(screen_buffer, "0"); return; }
    screen_buffer[0] = '\0';
    if (is_negative) appendCharacter(screen_buffer, '-');
    char temporary_buffer[32];
    longLongToString(integer_part, temporary_buffer);
    stringConcat(screen_buffer, temporary_buffer);
    if (fractional_remainder > 0) {
        appendCharacter(screen_buffer, '.');
        char fraction_digits[5];
        fraction_digits[0] = char('0' + (fractional_remainder / 1000) % 10);
        fraction_digits[1] = char('0' + (fractional_remainder / 100) % 10);
        fraction_digits[2] = char('0' + (fractional_remainder / 10) % 10);
        fraction_digits[3] = char('0' + fractional_remainder % 10);
        fraction_digits[4] = '\0';
        int k = 3;
        while (k >= 0 && fraction_digits[k] == '0') fraction_digits[k--] = '\0';
        stringConcat(screen_buffer, fraction_digits);
    }
}

bool parseLiteralNumber(const char s[], double &screen_buffer) {
    int length = stringLength(s), i = (length > 0 && s[0] == '-') ? 1 : 0;
    if (i >= length || s[i] < '0' || s[i] > '9') return false;
    double current_value = 0.0;
    while (i < length && s[i] >= '0' && s[i] <= '9') current_value = current_value * 10.0 + (s[i++] - '0');
    if (i < length) {
        if (s[i++] != '.' || i >= length || s[i] < '0' || s[i] > '9') return false;
        double fraction = 0.1;
        while (i < length && s[i] >= '0' && s[i] <= '9') {
            current_value += (s[i++] - '0') * fraction;
            fraction *= 0.1;
        }
    }
    screen_buffer = (length > 0 && s[0] == '-') ? -current_value : current_value;
    return i == length;
}

// tokenize formula
void addToken(int token_type, double current_value = 0.0, const char s[] = "", int r = -1, int c = -1) {
    token_types[token_count] = token_type;
    token_values[token_count] = current_value;
    stringCopy(token_strings[token_count], s);
    token_rows[token_count] = r;
    token_columns[token_count] = c;
    token_count++;
}

void tokenizeFormula(const char expr[]) {
    token_count = 0;
    int i = 0, length = stringLength(expr);
    while (i < length) {
        char current_char = expr[i];
        if (current_char == ' ' || current_char == '\t') { i++; continue; }
        if (current_char == '"') {
            i++;
            char literal_string[64];
            int k = 0;
            while (i < length && expr[i] != '"' && k < 63) literal_string[k++] = expr[i++];
            literal_string[k] = '\0';
            if (i >= length) { addToken(20); return; }
            i++;
            addToken(2, 0.0, literal_string);
            continue;
        }
        if (current_char >= '0' && current_char <= '9') {
            double current_value = 0.0;
            while (i < length && expr[i] >= '0' && expr[i] <= '9') current_value = current_value * 10.0 + (expr[i++] - '0');
            if (i < length && expr[i] == '.') {
                i++;
                if (i >= length || expr[i] < '0' || expr[i] > '9') { addToken(20); return; }
                double fraction = 0.1;
                while (i < length && expr[i] >= '0' && expr[i] <= '9') { current_value += (expr[i++] - '0') * fraction; fraction *= 0.1; }
                if (i < length && expr[i] == '.') { addToken(20); return; }
            }
            if (i < length && ((expr[i] >= 'A' && expr[i] <= 'Z') || (expr[i] >= 'a' && expr[i] <= 'z'))) {
                addToken(20);
                return;
            }
            addToken(1, current_value);
            continue;
        }
        if ((current_char >= 'A' && current_char <= 'Z') || (current_char >= 'a' && current_char <= 'z')) {
            char column_letters[64], row_digits[64];
            int letter_count = 0, digit_count = 0;
            while (i < length && ((expr[i] >= 'A' && expr[i] <= 'Z') || (expr[i] >= 'a' && expr[i] <= 'z')) && letter_count < 63)
                column_letters[letter_count++] = (expr[i] >= 'a') ? char(expr[i++] - 32) : expr[i++];
            column_letters[letter_count] = '\0';
            while (i < length && expr[i] >= '0' && expr[i] <= '9' && digit_count < 63) row_digits[digit_count++] = expr[i++];
            row_digits[digit_count] = '\0';
            if (i < length && ((expr[i] >= 'A' && expr[i] <= 'Z') || (expr[i] >= 'a' && expr[i] <= 'z'))) {
                while (i < length && ((expr[i] >= 'A' && expr[i] <= 'Z') || (expr[i] >= 'a' && expr[i] <= 'z') || (expr[i] >= '0' && expr[i] <= '9')) && letter_count < 63)
                    column_letters[letter_count++] = expr[i++];
                column_letters[letter_count] = '\0';
                addToken(4, 0.0, column_letters);
            } else if (digit_count > 0) {
                int r = 0;
                for (int k = 0; k < digit_count; k++) r = r < 1000 ? r * 10 + (row_digits[k] - '0') : r;
                bool ok = (letter_count == 1 && r >= 0 && r < MAX_ROWS);
                addToken(3, 0.0, "", ok ? r : -1, ok ? (column_letters[0] - 'A') : -1);
            } else {
                addToken(4, 0.0, column_letters);
            }
            continue;
        }
        if (current_char == '<' && i + 1 < length && expr[i + 1] == '>') { addToken(15); i += 2; continue; }
        if (current_char == '<' && i + 1 < length && expr[i + 1] == '=') { addToken(17); i += 2; continue; }
        if (current_char == '>' && i + 1 < length && expr[i + 1] == '=') { addToken(19); i += 2; continue; }
        int token_type = current_char == '+' ? 5 : current_char == '-' ? 6 : current_char == '*' ? 7 : current_char == '/' ? 8 :
                current_char == '^' ? 9 : current_char == '(' ? 10 : current_char == ')' ? 11 : current_char == ',' ? 12 :
                current_char == ':' ? 13 : current_char == '=' ? 14 : current_char == '<' ? 16 : current_char == '>' ? 18 : 20;
        addToken(token_type);
        i++;
        if (token_type == 20) return;
    }
    addToken(0);
}

// recursive parser
void evaluateCell(int r, int c);
void parseExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column);
void setError(int &value_type, char string_value[], const char msg[]) {
    value_type = t_err;
    stringCopy(string_value, msg);
}

void parsePrimaryExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    is_empty = false;
    string_value[0] = '\0';
    int token_type = token_types[token_position];
    if (token_type == 1) {
        value_type = t_num; numeric_value = token_values[token_position++];
        return;
    }
    if (token_type == 2) {
        value_type = t_str; stringCopy(string_value, token_strings[token_position++]);
        return;
    }
    if (token_type == 10) {
        token_position++;
        parseExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
        if (token_types[token_position] != 11) { syntax_error = true; return; }
        token_position++;
        if (!syntax_only && value_type == t_range) setError(value_type, string_value, "#VALUE!");
        return;
    }
    if (token_type == 3) {
        int ar = token_rows[token_position], ac = token_columns[token_position];
        token_position++;
        if (token_types[token_position] == 13) {
            token_position++;
            if (token_types[token_position] != 3) { syntax_error = true; return; }
            int br = token_rows[token_position], bc = token_columns[token_position];
            token_position++;
            if (syntax_only) return;
            if (ar < 0 || br < 0) { setError(value_type, string_value, "#REF!"); return; }
            value_type = t_range;
            start_row = ar < br ? ar : br; end_row = ar > br ? ar : br;
            start_column = ac < bc ? ac : bc; end_column = ac > bc ? ac : bc;
            return;
        }
        if (syntax_only) return;
        if (ar < 0) { setError(value_type, string_value, "#REF!"); return; }
        evaluateCell(ar, ac);
        int ct = cell_types[ar][ac];
        is_empty = (ct == t_empty);
        value_type = ct == t_empty ? t_num : ct;
        numeric_value = ct == t_empty ? 0.0 : cell_numbers[ar][ac];
        stringCopy(string_value, ct == t_str ? cell_strings[ar][ac] : (ct == t_err ? display_cells[ar][ac] : ""));
        return;
    }
    if (token_type == 4) {
        char function_name[64];
        stringCopy(function_name, token_strings[token_position++]);
        if (token_types[token_position] != 10) {
            if (!syntax_only) setError(value_type, string_value, "#NAME?");
            return;
        }
        token_position++;
        int argument_types[64], argument_start_rows[64], argument_start_columns[64], argument_end_rows[64], argument_end_columns[64], argument_count = 0;
        double argument_numbers[64];
        char argument_strings[64][MAX_STRING_SIZE];
        bool argument_is_empty[64];
        if (token_types[token_position] != 11) {
            while (true) {
                if (argument_count >= 64) { syntax_error = true; return; }
                parseExpression(syntax_only, argument_types[argument_count], argument_numbers[argument_count], argument_strings[argument_count], argument_is_empty[argument_count], argument_start_rows[argument_count], argument_start_columns[argument_count], argument_end_rows[argument_count], argument_end_columns[argument_count]);
                if (syntax_error) return;
                argument_count++;
                if (token_types[token_position] == 12) { token_position++; continue; }
                break;
            }
        }
        if (token_types[token_position] != 11) { syntax_error = true; return; }
        token_position++;
        if (syntax_only) return;
        bool is_aggregate_function = stringCompare(function_name, "SUM") == 0 || stringCompare(function_name, "AVG") == 0 || stringCompare(function_name, "MIN") == 0 ||
                      stringCompare(function_name, "MAX") == 0 || stringCompare(function_name, "COUNT") == 0 || stringCompare(function_name, "MEDIAN") == 0;
        if (is_aggregate_function) {
            if (argument_count < 1) { setError(value_type, string_value, "#VALUE!"); return; }
            double numeric_values[2048];
            int number_count = 0;
            for (int i = 0; i < argument_count; i++) {
                if (argument_types[i] == t_err) { setError(value_type, string_value, argument_strings[i]); return; }
                if (argument_types[i] == t_range) {
                    for (int rr = argument_start_rows[i]; rr <= argument_end_rows[i]; rr++) {
                        for (int cc = argument_start_columns[i]; cc <= argument_end_columns[i]; cc++) {
                            evaluateCell(rr, cc);
                            if (cell_types[rr][cc] == t_err) { setError(value_type, string_value, display_cells[rr][cc]); return; }
                            if (cell_types[rr][cc] == t_num) numeric_values[number_count++] = cell_numbers[rr][cc];
                        }
                    }
                } else if (argument_types[i] == t_num && !argument_is_empty[i]) {
                    numeric_values[number_count++] = argument_numbers[i];
                }
            }
            if (stringCompare(function_name, "COUNT") == 0) { value_type = t_num; numeric_value = (double)number_count; return; }
            if (stringCompare(function_name, "SUM") == 0 || stringCompare(function_name, "MIN") == 0 || stringCompare(function_name, "MAX") == 0) {
                if (number_count == 0) { value_type = t_num; numeric_value = 0.0; return; }
                double result = numeric_values[0];
                for (int i = 1; i < number_count; i++)
                    result = stringCompare(function_name, "SUM") == 0 ? result + numeric_values[i] :
                          (stringCompare(function_name, "MIN") == 0 ? (numeric_values[i] < result ? numeric_values[i] : result) : (numeric_values[i] > result ? numeric_values[i] : result));
                value_type = t_num; numeric_value = result; return;
            }
            if (stringCompare(function_name, "AVG") == 0) {
                if (number_count == 0) { setError(value_type, string_value, "#DIV/0!"); return; }
                double s = 0.0;
                for (int i = 0; i < number_count; i++) s += numeric_values[i];
                value_type = t_num; numeric_value = s / (double)number_count; return;
            }
            if (number_count == 0) { setError(value_type, string_value, "#NUM!"); return; }
            for (int i = 1; i < number_count; i++) {
                double key = numeric_values[i];
                int j = i - 1;
                while (j >= 0 && numeric_values[j] > key) { numeric_values[j + 1] = numeric_values[j]; j--; }
                numeric_values[j + 1] = key;
            }
            value_type = t_num;
            numeric_value = (number_count % 2 == 1) ? numeric_values[number_count / 2] : 0.5 * (numeric_values[number_count / 2 - 1] + numeric_values[number_count / 2]);
            return;
        }
        if (stringCompare(function_name, "CONCAT") == 0) {
            if (argument_count < 1) { setError(value_type, string_value, "#VALUE!"); return; }
            string_value[0] = '\0';
            for (int i = 0; i < argument_count; i++) {
                if (argument_types[i] == t_err) { setError(value_type, string_value, argument_strings[i]); return; }
                if (argument_types[i] == t_range) {
                    for (int rr = argument_start_rows[i]; rr <= argument_end_rows[i]; rr++) {
                        for (int cc = argument_start_columns[i]; cc <= argument_end_columns[i]; cc++) {
                            evaluateCell(rr, cc);
                            if (cell_types[rr][cc] == t_err) { setError(value_type, string_value, display_cells[rr][cc]); return; }
                            stringConcat(string_value, display_cells[rr][cc]);
                        }
                    }
                } else if (argument_types[i] == t_str) {
                    stringConcat(string_value, argument_strings[i]);
                } else if (!argument_is_empty[i]) {
                    char formatted_number[32];
                    formatNumber(argument_numbers[i], formatted_number);
                    if (stringCompare(formatted_number, "#NUM!") == 0) { setError(value_type, string_value, formatted_number); return; }
                    stringConcat(string_value, formatted_number);
                }
            }
            value_type = t_str; return;
        }
        if (stringCompare(function_name, "ABS") == 0 || stringCompare(function_name, "SQRT") == 0 || stringCompare(function_name, "LEN") == 0 || stringCompare(function_name, "UPPER") == 0) {
            if (argument_count != 1 || argument_types[0] == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
            if (argument_types[0] == t_err) { setError(value_type, string_value, argument_strings[0]); return; }
            if (stringCompare(function_name, "ABS") == 0 || stringCompare(function_name, "SQRT") == 0) {
                if (argument_types[0] != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
                if (stringCompare(function_name, "SQRT") == 0 && argument_numbers[0] < 0.0) { setError(value_type, string_value, "#NUM!"); return; }
                value_type = t_num; numeric_value = stringCompare(function_name, "ABS") == 0 ? doubleAbs(argument_numbers[0]) : calculateSquareRoot(argument_numbers[0]); return;
            }
            char sh[MAX_STRING_SIZE];
            sh[0] = '\0';
            if (argument_types[0] == t_str) stringCopy(sh, argument_strings[0]);
            else if (!argument_is_empty[0]) formatNumber(argument_numbers[0], sh);
            if (stringCompare(sh, "#NUM!") == 0) { setError(value_type, string_value, sh); return; }
            if (stringCompare(function_name, "LEN") == 0) { value_type = t_num; numeric_value = (double)stringLength(sh); return; }
            toUpperCase(sh);
            value_type = t_str; stringCopy(string_value, sh); return;
        }
        if (stringCompare(function_name, "ROUND") == 0 || stringCompare(function_name, "POW") == 0 || stringCompare(function_name, "MOD") == 0) {
            if (argument_count != 2 || argument_types[0] == t_range || argument_types[1] == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
            if (argument_types[0] == t_err) { setError(value_type, string_value, argument_strings[0]); return; }
            if (argument_types[1] == t_err) { setError(value_type, string_value, argument_strings[1]); return; }
            if (argument_types[0] != t_num || argument_types[1] != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
            if (stringCompare(function_name, "ROUND") == 0) {
                int decimal_places = (int)argument_numbers[1];
                if ((double)decimal_places != argument_numbers[1] || decimal_places < 0 || decimal_places > 9) { setError(value_type, string_value, "#VALUE!"); return; }
                value_type = t_num; numeric_value = roundDecimal(argument_numbers[0], decimal_places); return;
            }
            if (stringCompare(function_name, "MOD") == 0) {
                if (argument_numbers[1] == 0.0) { setError(value_type, string_value, "#DIV/0!"); return; }
                value_type = t_num; numeric_value = argument_numbers[0] - argument_numbers[1] * doubleFloor(argument_numbers[0] / argument_numbers[1]); return;
            }
            LongLong ex = (LongLong)argument_numbers[1];
            if (doubleAbs(argument_numbers[1]) >= 9e18 || (double)ex != argument_numbers[1] || (argument_numbers[0] == 0.0 && ex < 0)) { setError(value_type, string_value, "#NUM!"); return; }
            double result = 1.0, base = argument_numbers[0];
            LongLong power = ex < 0 ? -ex : ex;
            while (power > 0) {
                result *= (power % 2 == 1) ? base : 1.0;
                if (doubleAbs(result) >= 1e15) { setError(value_type, string_value, "#NUM!"); return; }
                power /= 2;
                base *= power > 0 ? base : 1.0;
            }
            value_type = t_num; numeric_value = ex < 0 ? 1.0 / result : result; return;
        }
        if (stringCompare(function_name, "IF") == 0) {
            if (argument_count != 3 || argument_types[0] == t_range || argument_types[1] == t_range || argument_types[2] == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
            if (argument_types[0] == t_err) { setError(value_type, string_value, argument_strings[0]); return; }
            if (argument_types[1] == t_err) { setError(value_type, string_value, argument_strings[1]); return; }
            if (argument_types[2] == t_err) { setError(value_type, string_value, argument_strings[2]); return; }
            if (argument_types[0] != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
            int selected_index = argument_numbers[0] != 0.0 ? 1 : 2;
            value_type = argument_types[selected_index]; numeric_value = argument_numbers[selected_index]; stringCopy(string_value, argument_strings[selected_index]); return;
        }
        setError(value_type, string_value, "#NAME?");
        return;
    }
    syntax_error = true;
}

void parseUnaryExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column);
void parsePowerExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parsePrimaryExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    if (syntax_error || token_types[token_position] != 9) return;
    token_position++;
    int right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
    double right_numeric_value;
    char right_string_value[MAX_STRING_SIZE];
    bool right_is_empty;
    parseUnaryExpression(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
    if (syntax_only || syntax_error) return;
    if (value_type == t_range || right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
    if (value_type == t_err) return;
    if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); return; }
    if (value_type != t_num || right_value_type != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
    LongLong ex = (LongLong)right_numeric_value;
    if (doubleAbs(right_numeric_value) >= 9e18 || (double)ex != right_numeric_value || (numeric_value == 0.0 && ex < 0)) { setError(value_type, string_value, "#NUM!"); return; }
    double result = 1.0, base = numeric_value;
    LongLong power = ex < 0 ? -ex : ex;
    while (power > 0) {
        result *= (power % 2 == 1) ? base : 1.0;
        if (doubleAbs(result) >= 1e15) { setError(value_type, string_value, "#NUM!"); return; }
        power /= 2;
        base *= power > 0 ? base : 1.0;
    }
    value_type = t_num; numeric_value = ex < 0 ? 1.0 / result : result; is_empty = false;
}

void parseUnaryExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    if (token_types[token_position] == 6) {
        token_position++;
        parseUnaryExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
        if (syntax_only || syntax_error) return;
        if (value_type == t_range) { setError(value_type, string_value, "#VALUE!"); return; }
        if (value_type == t_err) return;
        if (value_type != t_num) { setError(value_type, string_value, "#VALUE!"); return; }
        numeric_value = -numeric_value; is_empty = false;
        return;
    }
    parsePowerExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
}

void parseMultiplicationDivision(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parseUnaryExpression(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    while (!syntax_error && (token_types[token_position] == 7 || token_types[token_position] == 8)) {
        int operator_type = token_types[token_position++], right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
        double right_numeric_value;
        char right_string_value[MAX_STRING_SIZE];
        bool right_is_empty;
        parseUnaryExpression(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
        if (syntax_only || syntax_error) continue;
        if (value_type == t_range || right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (value_type == t_err) continue;
        if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); continue; }
        if (value_type != t_num || right_value_type != t_num) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (operator_type == 8 && right_numeric_value == 0.0) { setError(value_type, string_value, "#DIV/0!"); continue; }
        numeric_value = operator_type == 7 ? numeric_value * right_numeric_value : numeric_value / right_numeric_value;
        is_empty = false;
    }
}

void parseAdditionSubtraction(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parseMultiplicationDivision(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    while (!syntax_error && (token_types[token_position] == 5 || token_types[token_position] == 6)) {
        int operator_type = token_types[token_position++], right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
        double right_numeric_value;
        char right_string_value[MAX_STRING_SIZE];
        bool right_is_empty;
        parseMultiplicationDivision(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
        if (syntax_only || syntax_error) continue;
        if (value_type == t_range || right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (value_type == t_err) continue;
        if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); continue; }
        if (value_type != t_num || right_value_type != t_num) { setError(value_type, string_value, "#VALUE!"); continue; }
        numeric_value = operator_type == 5 ? numeric_value + right_numeric_value : numeric_value - right_numeric_value;
        is_empty = false;
    }
}

void parseExpression(bool syntax_only, int &value_type, double &numeric_value, char string_value[], bool &is_empty, int &start_row, int &start_column, int &end_row, int &end_column) {
    parseAdditionSubtraction(syntax_only, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
    while (!syntax_error && token_types[token_position] >= 14 && token_types[token_position] <= 19) {
        int operator_type = token_types[token_position++], right_value_type, right_start_row, right_start_column, right_end_row, right_end_column;
        double right_numeric_value;
        char right_string_value[MAX_STRING_SIZE];
        bool right_is_empty;
        parseAdditionSubtraction(syntax_only, right_value_type, right_numeric_value, right_string_value, right_is_empty, right_start_row, right_start_column, right_end_row, right_end_column);
        if (syntax_only || syntax_error) continue;
        if (value_type == t_range || right_value_type == t_range) { setError(value_type, string_value, "#VALUE!"); continue; }
        if (value_type == t_err) continue;
        if (right_value_type == t_err) { setError(value_type, string_value, right_string_value); continue; }
        if (value_type != right_value_type) { setError(value_type, string_value, "#VALUE!"); continue; }
        bool comparison = value_type == t_num
            ? (operator_type == 14 ? numeric_value == right_numeric_value : operator_type == 15 ? numeric_value != right_numeric_value : operator_type == 16 ? numeric_value < right_numeric_value : operator_type == 17 ? numeric_value <= right_numeric_value : operator_type == 18 ? numeric_value > right_numeric_value : numeric_value >= right_numeric_value)
            : (operator_type == 14 ? stringCompare(string_value, right_string_value) == 0 : operator_type == 15 ? stringCompare(string_value, right_string_value) != 0 : operator_type == 16 ? stringCompare(string_value, right_string_value) < 0 :
               operator_type == 17 ? stringCompare(string_value, right_string_value) <= 0 : operator_type == 18 ? stringCompare(string_value, right_string_value) > 0 : stringCompare(string_value, right_string_value) >= 0);
        value_type = t_num; numeric_value = comparison ? 1.0 : 0.0; is_empty = false;
    }
}

// evaluate cell
void evaluateCell(int r, int c) {
    if (visit_state[r][c] == 2) return;
    if (visit_state[r][c] == 1) {
        cell_types[r][c] = t_err;
        stringCopy(display_cells[r][c], "#CYCLE!");
        return;
    }
    visit_state[r][c] = 1;
    double current_value = 0.0;
    if (raw_cells[r][c][0] == '\0') {
        cell_types[r][c] = t_empty;
        display_cells[r][c][0] = '\0';
    } else if (raw_cells[r][c][0] == '=') {
        tokenizeFormula(raw_cells[r][c] + 1);
        int value_type = t_err, start_row = 0, start_column = 0, end_row = 0, end_column = 0;
        double numeric_value = 0.0;
        char string_value[MAX_STRING_SIZE];
        string_value[0] = '\0';
        bool is_empty = false;
        syntax_error = (token_count <= 1 || token_types[token_count - 2] == 20);
        token_position = 0;
        if (!syntax_error) parseExpression(true, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
        if (syntax_error || token_position != token_count - 1) {
            cell_types[r][c] = t_err;
            stringCopy(display_cells[r][c], "#SYNTAX!");
        } else {
            token_position = 0;
            parseExpression(false, value_type, numeric_value, string_value, is_empty, start_row, start_column, end_row, end_column);
            if (value_type == t_range) {
                cell_types[r][c] = t_err;
                stringCopy(display_cells[r][c], "#VALUE!");
            } else if (value_type == t_err) {
                cell_types[r][c] = t_err;
                stringCopy(display_cells[r][c], string_value);
            } else if (value_type == t_str) {
                cell_types[r][c] = t_str;
                stringCopy(cell_strings[r][c], string_value);
                stringCopy(display_cells[r][c], string_value);
            } else {
                char formatted_number[32];
                formatNumber(numeric_value, formatted_number);
                cell_types[r][c] = stringCompare(formatted_number, "#NUM!") == 0 ? t_err : t_num;
                cell_numbers[r][c] = numeric_value;
                stringCopy(display_cells[r][c], formatted_number);
            }
        }
    } else if (parseLiteralNumber(raw_cells[r][c], current_value)) {
        char formatted_number[32];
        formatNumber(current_value, formatted_number);
        cell_types[r][c] = stringCompare(formatted_number, "#NUM!") == 0 ? t_err : t_num;
        cell_numbers[r][c] = current_value;
        stringCopy(display_cells[r][c], formatted_number);
    } else {
        cell_types[r][c] = t_str;
        stringCopy(cell_strings[r][c], raw_cells[r][c]);
        stringCopy(display_cells[r][c], raw_cells[r][c]);
    }
    visit_state[r][c] = 2;
}

void recalculateAllCells() {
    for (int r = 0; r < MAX_ROWS; r++)
        for (int c = 0; c < MAX_COLS; c++) visit_state[r][c] = 0;
    for (int r = 0; r < MAX_ROWS; r++)
        for (int c = 0; c < MAX_COLS; c++)
            if (visit_state[r][c] == 0) evaluateCell(r, c);
    for (int c = 0; c < MAX_COLS; c++) {
        int w = 8;
        for (int r = 0; r < MAX_ROWS; r++) {
            int ln = stringLength(display_cells[r][c]);
            w = ln > w ? ln : w;
        }
        column_widths[c] = w;
    }
}

int getLastVisibleColumn(int left_visible_column) {
    int used = 6, c = left_visible_column;
    while (c < MAX_COLS && used + column_widths[c] + 3 <= SCREEN_WIDTH) used += column_widths[c++] + 3;
    return c > left_visible_column ? c - 1 : left_visible_column;
}

// render screen
void appendString(char screen_buffer[], int &output_index, const char s[]) {
    for (int i = 0; s[i] != '\0'; i++) screen_buffer[output_index++] = s[i];
}

void appendRepeatedCharacter(char screen_buffer[], int &output_index, char current_char, int cnt) {
    for (int i = 0; i < cnt; i++) screen_buffer[output_index++] = current_char;
}

void renderSpreadsheet(int current_row, int current_column, int &top_visible_row, int &left_visible_column, bool is_editing) {
    top_visible_row = current_row < top_visible_row ? current_row : (current_row >= top_visible_row + VISIBLE_ROWS ? current_row - VISIBLE_ROWS + 1 : top_visible_row);
    left_visible_column = current_column < left_visible_column ? current_column : left_visible_column;
    while (current_column > getLastVisibleColumn(left_visible_column)) left_visible_column++;
    int right_visible_column = getLastVisibleColumn(left_visible_column);
    char table_separator[200], cell_address[8], number_buffer[16], screen_buffer[4800];
    int separator_index = 0, output_index = 0;
    appendString(table_separator, separator_index, "+----+");
    for (int c = left_visible_column; c <= right_visible_column; c++) {
        appendRepeatedCharacter(table_separator, separator_index, '-', column_widths[c] + 2);
        table_separator[separator_index++] = '+';
    }
    table_separator[separator_index] = '\0';
    getCellAddress(current_row, current_column, cell_address);
    appendString(screen_buffer, output_index, cell_address);
    appendString(screen_buffer, output_index, " > ");
    appendString(screen_buffer, output_index, raw_cells[current_row][current_column]);
    screen_buffer[output_index++] = '\n';
    appendString(screen_buffer, output_index, table_separator);
    screen_buffer[output_index++] = '\n';
    appendString(screen_buffer, output_index, "|    |");
    for (int c = left_visible_column; c <= right_visible_column; c++) {
        int left_padding = (column_widths[c] - 1) / 2, right_padding = column_widths[c] - 1 - left_padding;
        screen_buffer[output_index++] = ' ';
        appendRepeatedCharacter(screen_buffer, output_index, ' ', left_padding);
        screen_buffer[output_index++] = char('A' + c);
        appendRepeatedCharacter(screen_buffer, output_index, ' ', right_padding);
        appendString(screen_buffer, output_index, " |");
    }
    screen_buffer[output_index++] = '\n';
    appendString(screen_buffer, output_index, table_separator);
    screen_buffer[output_index++] = '\n';
    for (int r = top_visible_row; r < top_visible_row + VISIBLE_ROWS; r++) {
        appendString(screen_buffer, output_index, r < 10 ? "|  " : "| ");
        longLongToString(r, number_buffer);
        appendString(screen_buffer, output_index, number_buffer);
        appendString(screen_buffer, output_index, " |");
        for (int c = left_visible_column; c <= right_visible_column; c++) {
            int cell_padding = column_widths[c] - stringLength(display_cells[r][c]);
            bool is_selected = (r == current_row && c == current_column);
            screen_buffer[output_index++] = is_selected ? '[' : ' ';
            if (cell_types[r][c] == t_num) {
                appendRepeatedCharacter(screen_buffer, output_index, ' ', cell_padding);
                appendString(screen_buffer, output_index, display_cells[r][c]);
            } else {
                appendString(screen_buffer, output_index, display_cells[r][c]);
                appendRepeatedCharacter(screen_buffer, output_index, ' ', cell_padding);
            }
            screen_buffer[output_index++] = is_selected ? ']' : ' ';
            screen_buffer[output_index++] = '|';
        }
        screen_buffer[output_index++] = '\n';
    }
    appendString(screen_buffer, output_index, table_separator);
    screen_buffer[output_index++] = '\n';
    if (is_editing) {
        appendString(screen_buffer, output_index, cell_address);
        appendString(screen_buffer, output_index, " > ");
    } else {
        appendString(screen_buffer, output_index, "Arrows: move   Enter: edit   Delete: clear   Q: quit");
    }
    screen_buffer[output_index] = '\0';
    clearScreen();
    cout << screen_buffer;
    cout.flush();
}

// main loop
int main() {
    int current_row = 0, current_column = 0, top_visible_row = 0, left_visible_column = 0;
    recalculateAllCells();
    while (true) {
        renderSpreadsheet(current_row, current_column, top_visible_row, left_visible_column, false);
        int pressed_key = readKey();
        if (pressed_key == 'q' || pressed_key == 'Q') return 0;
        current_row = pressed_key == KEY_UP ? (current_row > 0 ? current_row - 1 : 0) : (pressed_key == KEY_DOWN ? (current_row + 1 < MAX_ROWS ? current_row + 1 : MAX_ROWS - 1) : current_row);
        current_column = pressed_key == KEY_LEFT ? (current_column > 0 ? current_column - 1 : 0) : (pressed_key == KEY_RIGHT ? (current_column + 1 < MAX_COLS ? current_column + 1 : MAX_COLS - 1) : current_column);
        if (pressed_key == KEY_DELETE) {
            raw_cells[current_row][current_column][0] = '\0';
            recalculateAllCells();
        } else if (pressed_key == KEY_ENTER) {
            renderSpreadsheet(current_row, current_column, top_visible_row, left_visible_column, true);
            char input_buffer[64], current_char;
            int input_length = 0;
            while (cin.get(current_char) && current_char != '\n')
                if (current_char >= 32 && current_char <= 126 && input_length < 60) input_buffer[input_length++] = current_char;
            input_buffer[input_length] = '\0';
            if (input_length > 0) {
                stringCopy(raw_cells[current_row][current_column], input_buffer);
                recalculateAllCells();
            }
        }
    }
    return 0;
}
