#ifndef URG_RING_BUFFER_H
#define URG_RING_BUFFER_H

/*!
  \file
  \brief functions to handle ring buffer

  \author Satofumi KAMIMURA

  $Id: urg_ring_buffer.h,v acb362e60f78 2014/09/10 05:36:24 jun $
*/

#ifdef __cplusplus
extern "C" {
#endif

//! ring buffer handler
typedef struct
{
    char *buffer;                 //!< pointer
    int buffer_size;              //!< buffer size
    int first;                    //!< start point of buffer
    int last;                     //!< end point of buffer
} ring_buffer_t;


/*!
  \brief function to initialize ring buffer

  \param[in] ring handler
  \param[in] buffer memory for ring buffer
  \param[in] shift_length log2-scaled buffer size (buffer size is 2^{shift_length})
*/
extern void ring_initialize(ring_buffer_t *ring,
                            char *buffer, const int shift_length);


/*!
  \brief function to clear ring buffer

  \param[in] ring handler
*/
extern void ring_clear(ring_buffer_t *ring);


/*!
  \brief function to return amount of stored data

  \param[in] ring handler
*/
extern int ring_size(const ring_buffer_t *ring);


/*!
  \brief function to return maximum amount of stored data

  \param[in] ring handler
*/
extern int ring_capacity(const ring_buffer_t *ring);


/*!
  \brief function to store data in ring buffer

  \param[in] ring handler handler
  \param[in] data data to store
  \param[in] size size of data

  \return amount of stored data
*/
extern int ring_write(ring_buffer_t *ring, const char *data, int size);


/*!
  \brief function to read data from ring buffer

  \param[in] ring handler
  \param[out] buffer data
  \param[in] size maximum data size

  \return amount of read data
*/
extern int ring_read(ring_buffer_t *ring, char *buffer, int size);

#ifdef __cplusplus
}
#endif

#endif /* ! RING_BUFFER_H */
