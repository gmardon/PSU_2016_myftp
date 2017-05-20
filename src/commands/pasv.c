#include "myftp.h"

void send_pasv_informations(t_client *client, char *ip, int port)
{
    int fport;
    int sport;

    fport = port / 256;
    sport = port % 256;
    send_message(client, "227 Entering Passive Mode (127,0,0,1,%d,%d).\r\n", fport, sport);
}

int use_pasv(t_client *client) 
{
    int sock;
    int client_fd;
    struct sockaddr_in sin;
    int port;

    port = 1024;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        return (-1);
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(port);
    sin.sin_family = AF_INET;
    while (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0)
    {
        port++;
        if (port > 65535)
            return (-1);
        sin.sin_port = htons(port);
    }
    if (listen(sock, 1) < 0)
        return (-1);
    //ipaddr = get_ip();
    send_pasv_informations(client, 0, port);
    return (accept(sock, NULL, NULL));
}

// TODO Add verification on all transfert functions (if user set port or pasv)
void handle_pasv(char **parameters, t_client *client) 
{
    //char *ipaddr;
    client->active_mode = 0;
    if ((client->data_fd = use_pasv(client)) == -1)
        send_message(client, "501 PASV command failed\r\n");
}
