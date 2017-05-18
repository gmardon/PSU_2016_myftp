#include "myftp.h"

void handle_type(char **parameters, t_client *client) 
{
    client->transfert_type = strdup(*parameters);
    send_data(client, "200 Type setted\r\n");
}

/*
Sets the type of file to be transferred. type-character can be any of:

A - ASCII text
E - EBCDIC text
I - image (binary data)
L - local format
For A and E, the second-type-character specifies how the text should be interpreted. It can be:
N - Non-print (not destined for printing). This is the default if second-type-character is omitted.
T - Telnet format control (<CR>, <FF>, etc.)
C - ASA Carriage Control
For L, the second-type-character specifies the number of bits per byte on the local system, and may not be omitted.
*/