
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int value1 = 0, value2 = 0;
    int addoutput = 0, suboutputA_B = 0, suboutputB_A = 0;
    int multLow = 0, multHigh = 0, quotoutput = 0, remoutput = 0;
    char sign_choice;
    bool is_signed, valid;
    int temp, digit, len;
    bool only_binary;

    // INPUT A
    valid = false;
    while (!valid) {
        cout << "Input A : ";
        cin >> value1;

        if (value1 < 0) {
            cout << "Input must be greater than or equal to 0.\n";
            continue;
        }

        temp = value1;
        len = 0;
        only_binary = true;

        if (temp == 0) len = 1;

        while (temp > 0) {
            digit = temp % 10;
            if (digit != 0 && digit != 1) only_binary = false;
            len++;
            temp /= 10;
        }

        if (!only_binary || len > 6) {
            cout << "Invalid input. Enter only 0s and 1s, max 6 digits.\n";
            continue;
        }

        valid = true;
    }

    // INPUT B
    valid = false;
    while (!valid) {
        cout << "Input B : ";
        cin >> value2;

        if (value2 < 0) {
            cout << "Input must be greater than or equal to 0.\n";
            continue;
        }

        temp = value2;
        len = 0;
        only_binary = true;

        if (temp == 0) len = 1;

        while (temp > 0) {
            digit = temp % 10;
            if (digit != 0 && digit != 1) only_binary = false;
            len++;
            temp /= 10;
        }

        if (!only_binary || len > 6) {
            cout << "Invalid input. Enter only 0s and 1s, max 6 digits.\n";
            continue;
        }

        valid = true;
    }

    cout << "Are these numbers signed or unsigned? Y/N: ";
    cin >> sign_choice;
    is_signed = (sign_choice == 'Y' || sign_choice == 'y');

    int p10_5 = 100000;
    int bin_val, bits_len, dec_val, cur_p10, cur_p2;
    bool check_sign;

    // DISPLAY A IN DECIMAL
    bin_val = value1;
    bits_len = 6;
    check_sign = is_signed;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (check_sign && ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    cout << "A : " << dec_val << '\n';

    // DISPLAY B IN DECIMAL
    bin_val = value2;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < 5; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (check_sign && ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    cout << "B : " << dec_val << '\n';

    int sign_ext_A = is_signed ? (value1 / p10_5) % 10 : 0;
    int sign_ext_B = is_signed ? (value2 / p10_5) % 10 : 0;
    int p10_i, carry, s;

    // ADDITION
    int addoutput7 = 0;
    carry = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitA = (i < 6) ? (value1 / p10_i) % 10 : sign_ext_A;
        int bitB = (i < 6) ? (value2 / p10_i) % 10 : sign_ext_B;

        s = bitA + bitB + carry;

        if (i < 6)
            addoutput += (s % 2) * p10_i;

        addoutput7 += (s % 2) * p10_i;
        carry = s / 2;
        p10_i *= 10;
    }

    bool ovf_add = false;

    if (is_signed) {
        int bitA5 = (value1 / p10_5) % 10;
        int bitB5 = (value2 / p10_5) % 10;
        int sum5 = (addoutput / p10_5) % 10;

        if (bitA5 == bitB5 && sum5 != bitA5)
            ovf_add = true;
    } else {
        if ((addoutput7 / 1000000) % 10 != 0)
            ovf_add = true;
    }

    if (ovf_add) {
        bin_val = addoutput7;
        bits_len = 7;
    } else {
        bin_val = addoutput;
        bits_len = 6;
    }

    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (is_signed && ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    if (ovf_add)
        cout << "A + B = " << setw(7) << setfill('0') << addoutput7
             << " = " << dec_val << "\toverflow detected\n";
    else
        cout << "A + B = " << setw(6) << setfill('0') << addoutput
             << " = " << dec_val << "\tno overflow\n";

    // A - B: COMPLEMENT B AND ADD 1
    int compB7 = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitB = (i < 6) ? (value2 / p10_i) % 10 : sign_ext_B;
        compB7 += (1 - bitB) * p10_i;
        p10_i *= 10;
    }

    int negB7 = 0;
    int c = 1;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bit = (compB7 / p10_i) % 10;
        s = bit + c;
        negB7 += (s % 2) * p10_i;
        c = s / 2;
        p10_i *= 10;
    }

    int suboutputA_B7 = 0;
    carry = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitA = (i < 6) ? (value1 / p10_i) % 10 : sign_ext_A;
        int bitNegB = (negB7 / p10_i) % 10;

        s = bitA + bitNegB + carry;

        if (i < 6)
            suboutputA_B += (s % 2) * p10_i;

        suboutputA_B7 += (s % 2) * p10_i;
        carry = s / 2;
        p10_i *= 10;
    }

    bool ovf_subA_B = false;

    if (is_signed) {
        int bitA5 = (value1 / p10_5) % 10;
        int bitB5 = (value2 / p10_5) % 10;
        int sum5 = (suboutputA_B / p10_5) % 10;

        if (bitA5 != bitB5 && sum5 != bitA5)
            ovf_subA_B = true;
    } else {
        if (carry == 0)
            ovf_subA_B = true;
    }

    bin_val = ovf_subA_B ? suboutputA_B7 : suboutputA_B;
    bits_len = ovf_subA_B ? 7 : 6;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (is_signed && ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    if (ovf_subA_B)
        cout << "A - B = " << setw(7) << setfill('0') << suboutputA_B7
             << " = " << dec_val << "\toverflow detected\n";
    else
        cout << "A - B = " << setw(6) << setfill('0') << suboutputA_B
             << " = " << dec_val << "\tno overflow\n";

    // B - A: COMPLEMENT A AND ADD 1
    int compA7 = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitA = (i < 6) ? (value1 / p10_i) % 10 : sign_ext_A;
        compA7 += (1 - bitA) * p10_i;
        p10_i *= 10;
    }

    int negA7 = 0;
    c = 1;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bit = (compA7 / p10_i) % 10;
        s = bit + c;
        negA7 += (s % 2) * p10_i;
        c = s / 2;
        p10_i *= 10;
    }

    int suboutputB_A7 = 0;
    carry = 0;
    p10_i = 1;

    for (int i = 0; i < 7; i++) {
        int bitB = (i < 6) ? (value2 / p10_i) % 10 : sign_ext_B;
        int bitNegA = (negA7 / p10_i) % 10;

        s = bitB + bitNegA + carry;

        if (i < 6)
            suboutputB_A += (s % 2) * p10_i;

        suboutputB_A7 += (s % 2) * p10_i;
        carry = s / 2;
        p10_i *= 10;
    }

    bool ovf_subB_A = false;

    if (is_signed) {
        int bitA5 = (value1 / p10_5) % 10;
        int bitB5 = (value2 / p10_5) % 10;
        int sum5 = (suboutputB_A / p10_5) % 10;

        if (bitB5 != bitA5 && sum5 != bitB5)
            ovf_subB_A = true;
    } else {
        if (carry == 0)
            ovf_subB_A = true;
    }

    bin_val = ovf_subB_A ? suboutputB_A7 : suboutputB_A;
    bits_len = ovf_subB_A ? 7 : 6;
    dec_val = 0;
    cur_p10 = 1;
    cur_p2 = 1;

    for (int i = 0; i < bits_len - 1; i++) {
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
        cur_p10 *= 10;
        cur_p2 *= 2;
    }

    if (is_signed && ((bin_val / cur_p10) % 10 == 1))
        dec_val -= cur_p2;
    else
        dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

    if (ovf_subB_A)
        cout << "B - A = " << setw(7) << setfill('0') << suboutputB_A7
             << " = " << dec_val << "\toverflow detected\n";
    else
        cout << "B - A = " << setw(6) << setfill('0') << suboutputB_A
             << " = " << dec_val << "\tno overflow\n";

    // GET POSITIVE MAGNITUDES FOR MULTIPLICATION AND DIVISION
    int magA_mul = value1;
    int magB_mul = value2;

    if (is_signed && (value1 / p10_5) % 10 == 1) {
        int comp = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            comp += (1 - ((value1 / p10_i) % 10)) * p10_i;
            p10_i *= 10;
        }

        c = 1;
        magA_mul = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (comp / p10_i) % 10 + c;
            magA_mul += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }
    }

    if (is_signed && (value2 / p10_5) % 10 == 1) {
        int comp = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            comp += (1 - ((value2 / p10_i) % 10)) * p10_i;
            p10_i *= 10;
        }

        c = 1;
        magB_mul = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (comp / p10_i) % 10 + c;
            magB_mul += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }
    }

    // MULTIPLICATION: TWO SIX-BIT CHUNKS, NO ARRAYS
    for (int i = 0; i < 6; i++) {
        int p10_shift = 1;

        for (int k = 0; k < i; k++)
            p10_shift *= 10;

        if ((magB_mul / p10_shift) % 10 == 1) {
            int newLow = 0, newHigh = 0;
            int p10_j = 1;
            carry = 0;

            for (int j = 0; j < 12; j++) {
                int bit_mult;
                int bit_shifted = 0;

                if (j < 6)
                    bit_mult = (multLow / p10_j) % 10;
                else
                    bit_mult = (multHigh / p10_j) % 10;

                if (j >= i && j - i < 6) {
                    int sourcePower = 1;

                    for (int k = 0; k < j - i; k++)
                        sourcePower *= 10;

                    bit_shifted = (magA_mul / sourcePower) % 10;
                }

                s = bit_mult + bit_shifted + carry;
                int outBit = s % 2;
                carry = s / 2;

                if (j < 6)
                    newLow += outBit * p10_j;
                else
                    newHigh += outBit * p10_j;

                if (j == 5 || j == 11)
                    p10_j = 1;
                else
                    p10_j *= 10;
            }

            multLow = newLow;
            multHigh = newHigh;
        }
    }

    // NEGATE THE 12-BIT PRODUCT IF REQUIRED
    bool is_mul_neg = is_signed &&
        (((value1 / p10_5) % 10) != ((value2 / p10_5) % 10));

    if (is_mul_neg) {
        int compLow = 0, compHigh = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            compLow += (1 - ((multLow / p10_i) % 10)) * p10_i;
            compHigh += (1 - ((multHigh / p10_i) % 10)) * p10_i;
            p10_i *= 10;
        }

        multLow = 0;
        c = 1;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (compLow / p10_i) % 10 + c;
            multLow += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }

        multHigh = 0;
        p10_i = 1;

        for (int i = 0; i < 6; i++) {
            s = (compHigh / p10_i) % 10 + c;
            multHigh += (s % 2) * p10_i;
            c = s / 2;
            p10_i *= 10;
        }
    }

    int decimalProduct = 0;
    int productPower = 1;
    p10_i = 1;

    for (int i = 0; i < 12; i++) {
        int bit;

        if (i < 6)
            bit = (multLow / p10_i) % 10;
        else
            bit = (multHigh / p10_i) % 10;

        decimalProduct += bit * productPower;
        productPower *= 2;

        if (i == 5)
            p10_i = 1;
        else
            p10_i *= 10;
    }

    if (is_signed && (multHigh / 100000) % 10 == 1)
        decimalProduct -= 4096;

    cout << "A * B = " << setw(6) << setfill('0') << multHigh << setw(6) << setfill('0') << multLow << " = " << decimalProduct << "\t\tmust be 12 bits/digits long, sign/unsigned according to input\n";

    // DIVISION AND MODULO
    if (magB_mul == 0) {
        cout << "Division by zero is undefined.\n";
    } else {
        quotoutput = 0;
        remoutput = 0;

        for (int i = 5; i >= 0; i--) {
            int shiftPower = 1;

            for (int k = 0; k < i; k++)
                shiftPower *= 10;

            int incomingBit = (magA_mul / shiftPower) % 10;

            remoutput = remoutput * 10 + incomingBit;

            bool gte = true;
            int p10_k = 100000;

            for (int k = 5; k >= 0; k--) {
                int r_bit = (remoutput / p10_k) % 10;
                int b_bit = (magB_mul / p10_k) % 10;

                if (r_bit > b_bit) {
                    gte = true;
                    break;
                }

                if (r_bit < b_bit) {
                    gte = false;
                    break;
                }

                p10_k /= 10;
            }

            if (gte) {
                int compB = 0;
                p10_k = 1;

                for (int k = 0; k < 6; k++) {
                    compB += (1 - ((magB_mul / p10_k) % 10)) * p10_k;
                    p10_k *= 10;
                }

                int negB = 0;
                int cy = 1;
                p10_k = 1;

                for (int k = 0; k < 6; k++) {
                    s = (compB / p10_k) % 10 + cy;
                    negB += (s % 2) * p10_k;
                    cy = s / 2;
                    p10_k *= 10;
                }

                int newRem = 0;
                cy = 0;
                p10_k = 1;

                for (int k = 0; k < 6; k++) {
                    s = ((remoutput / p10_k) % 10)
                      + ((negB / p10_k) % 10) + cy;

                    newRem += (s % 2) * p10_k;
                    cy = s / 2;
                    p10_k *= 10;
                }

                remoutput = newRem;

                int qPower = 1;

                for (int k = 0; k < i; k++)
                    qPower *= 10;

                quotoutput += qPower;
            }
        }

        // NEGATE QUOTIENT WHEN SIGNS DIFFER
        if (is_signed &&
            (((value1 / p10_5) % 10) != ((value2 / p10_5) % 10))) {

            int compQ = 0;
            int p10_k = 1;

            for (int k = 0; k < 6; k++) {
                compQ += (1 - ((quotoutput / p10_k) % 10)) * p10_k;
                p10_k *= 10;
            }

            int negQ = 0;
            int cy = 1;
            p10_k = 1;

            for (int k = 0; k < 6; k++) {
                s = (compQ / p10_k) % 10 + cy;
                negQ += (s % 2) * p10_k;
                cy = s / 2;
                p10_k *= 10;
            }

            quotoutput = negQ;
        }

        // NEGATE REMAINDER WHEN DIVIDEND IS NEGATIVE
        if (is_signed && (value1 / p10_5) % 10 == 1) {
            int compR = 0;
            int p10_k = 1;

            for (int k = 0; k < 6; k++) {
                compR += (1 - ((remoutput / p10_k) % 10)) * p10_k;
                p10_k *= 10;
            }

            int negR = 0;
            int cy = 1;
            p10_k = 1;

            for (int k = 0; k < 6; k++) {
                s = (compR / p10_k) % 10 + cy;
                negR += (s % 2) * p10_k;
                cy = s / 2;
                p10_k *= 10;
            }

            remoutput = negR;
        }

        // DISPLAY QUOTIENT
        bin_val = quotoutput;
        dec_val = 0;
        cur_p10 = 1;
        cur_p2 = 1;

        for (int i = 0; i < 5; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10;
            cur_p2 *= 2;
        }

        if (is_signed && ((bin_val / cur_p10) % 10 == 1))
            dec_val -= cur_p2;
        else
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

        cout << "A / B = " << setw(6) << setfill('0') << quotoutput
             << " = " << dec_val << "\t\tgive only the quotient\n";

        // DISPLAY REMAINDER
        bin_val = remoutput;
        dec_val = 0;
        cur_p10 = 1;
        cur_p2 = 1;

        for (int i = 0; i < 5; i++) {
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;
            cur_p10 *= 10;
            cur_p2 *= 2;
        }

        if (is_signed && ((bin_val / cur_p10) % 10 == 1))
            dec_val -= cur_p2;
        else
            dec_val += ((bin_val / cur_p10) % 10) * cur_p2;

        cout << "A % B = " << setw(6) << setfill('0') << remoutput
             << " = " << dec_val << "\t\tgive only the remainder, inheriting sign of dividend\n";
    }

    return 0;
}
