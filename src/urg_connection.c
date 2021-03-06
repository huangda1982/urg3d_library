/*!
  \file
  \brief functions to handle communication with urg sensor (ethernet)

  \author Satofumi KAMIMURA

  $Id: urg_connection.c,v 67b996051e49 2014/07/17 01:07:06 jun $
*/

#include "urg_connection.h"


int connection_open(urg_connection_t *connection
                    , urg_connection_type_t connection_type
                    , const char *device, long baudrate_or_port)
{
    connection->type = connection_type;

    switch (connection_type) {
    /*
    case URG_SERIAL:
        return serial_open(&connection->serial, device, baudrate_or_port);
        break;
    */
    case URG_ETHERNET:
        return tcpclient_open(&connection->tcpclient,
                              device, baudrate_or_port);
        break;
    }
    return -1;
}


void connection_close(urg_connection_t *connection)
{
    switch (connection->type) {
    /*
    case URG_SERIAL:
        serial_close(&connection->serial);
        break;
    */
    case URG_ETHERNET:
        tcpclient_close(&connection->tcpclient);
        break;
    }
}


int connection_set_baudrate(urg_connection_t *connection
                            , long baudrate)
{
    int ret = -1;

    switch (connection->type) {
    /*
    case URG_SERIAL:
        ret = serial_set_baudrate(&connection->serial, baudrate);
        break;
    */
    case URG_ETHERNET:
        ret = 0;
        break;
    }

    return ret;
}


int connection_write(urg_connection_t *connection
                     , const char *data
                     , int size)
{
    switch (connection->type) {
    /*
    case URG_SERIAL:
        return serial_write(&connection->serial, data, size);
        break;
    */
    case URG_ETHERNET:
        return tcpclient_write(&connection->tcpclient, data, size);
        break;
    }
    return -1;
}


int connection_read(urg_connection_t *connection
                    , char *data
                    , int max_size
                    , int timeout)
{
    switch (connection->type) {
    /*
    case URG_SERIAL:
        return serial_read(&connection->serial, data, max_size, timeout);
        break;
    */
    case URG_ETHERNET:
        return tcpclient_read(&connection->tcpclient, data, max_size, timeout);
        break;
    }
    return -1;
}
