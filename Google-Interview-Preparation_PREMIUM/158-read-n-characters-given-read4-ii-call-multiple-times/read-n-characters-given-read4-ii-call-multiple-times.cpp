/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */

    // Buffer to store data read from read4
    char buf4[4];
    // Index in buf4 and number of characters read into buf4
    int i4 = 0, n4 = 0;

    int read(char *buf, int n) {
        int i = 0;  // Pointer for the final buffer
        while (i < n) {
            // If we've consumed all characters in buf4, read new characters
            if (i4 == n4) {
                n4 = read4(buf4);  // Read into buf4
                i4 = 0;            // Reset index
                if (n4 == 0) break;  // No more characters to read
            }

            // Copy from buf4 to buf
            while (i < n && i4 < n4) {
                buf[i++] = buf4[i4++];
            }
        }
        return i;
    }
};