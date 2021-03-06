/**
 * \file deisterbufferparser.cpp
 * \author Adrien J. <adrien.jund@islog.com>
 * \brief Deister buffer parser.
 */

#include <logicalaccess/plugins/readers/deister/readercardadapters/deisterbufferparser.hpp>

namespace logicalaccess
{
ByteVector DeisterBufferParser::getValidBuffer(
    boost::circular_buffer<unsigned char> &circular_buffer)
{
    ByteVector result;
    const unsigned char STOP = 0xFE;

    if (circular_buffer.size() >= 10)
    {
        for (size_t i = 7; i < circular_buffer.size(); ++i)
        {
            if (circular_buffer[i] == STOP)
            {
                result.assign(circular_buffer.begin(), circular_buffer.begin() + i + 1);
                circular_buffer.erase(circular_buffer.begin(),
                                      circular_buffer.begin() + i + 1);
                break;
            }
        }
    }
    return result;
}
}