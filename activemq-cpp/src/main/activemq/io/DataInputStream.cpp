/* 
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <activemq/io/DataInputStream.h>
#include <activemq/util/Endian.h>

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::util;
using namespace activemq::exceptions;

////////////////////////////////////////////////////////////////////////////////
DataInputStream::DataInputStream( InputStream* inputStream, bool own )
 : FilterInputStream( inputStream, own ) {}

////////////////////////////////////////////////////////////////////////////////
DataInputStream::~DataInputStream() {}

////////////////////////////////////////////////////////////////////////////////
int DataInputStream::read( std::vector<unsigned char>& buffer ) 
    throw ( io::IOException ) {
        
    try {
        return this->read( &buffer[0], 0, buffer.size() );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int DataInputStream::read( unsigned char* buffer, int offset, int length ) 
    throw ( io::IOException, exceptions::IndexOutOfBoundsException, exceptions::NullPointerException ) {

    if( length < 0 || offset < 0 ) {
        throw IndexOutOfBoundsException( 
            __FILE__, __LINE__,
            "DataInputStream::read - len or offset params invalid" );
    }
    
    if( buffer == NULL ) {
        throw NullPointerException( 
            __FILE__, __LINE__,
            "DataInputStream::read - Buffer is null" );
    }
    
    try {
        int read = 0;
        
        try {
            read = inputStream->read( &buffer[offset], length );
        } catch( io::EOFException& ex ){
            if( read == 0 ) 
                return -1;
        }

        if( read == 0 ){
            throw IOException( 
                __FILE__, __LINE__,
                "DataInputStream::read - failed to extract data, not EOF." );
        }
        
        return read;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
bool DataInputStream::readBoolean() 
    throw( io::IOException, io::EOFException ) {

    try {
        char value = 0;
        this->readFully( ( unsigned char* )&value, 0, sizeof( char ) );
        return (char)( value != 0 );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
char DataInputStream::readByte() 
    throw ( io::IOException, io::EOFException ) {
    
    try {
        char value = 0;
        this->readFully( ( unsigned char* )&value, 0, sizeof( char ) );
        return (char)( value );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
unsigned char DataInputStream::readUnsignedByte() 
    throw ( io::IOException, io::EOFException ) {

    try {
        unsigned char value = 0;
        this->readFully( ( unsigned char* )&value, 0, sizeof( unsigned char ) );
        return (char)( value );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
} 

////////////////////////////////////////////////////////////////////////////////
char DataInputStream::readChar() throw ( io::IOException, io::EOFException ) {
    try {
        char value = 0;
        this->readFully( ( unsigned char* )&value, 0, sizeof( char ) );
        return (char)( value );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
short DataInputStream::readShort() throw ( io::IOException, io::EOFException ) {
    try {
        unsigned short value = 0;

        unsigned char byte1 = this->readByte();
        unsigned char byte2 = this->readByte();
        
        value |= (byte1 << 8 | byte2 << 0);
        
        return value;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
unsigned short DataInputStream::readUnsignedShort() 
    throw ( io::IOException, io::EOFException ) {
    try {

        unsigned short value = 0;

        unsigned char byte1 = this->readByte();
        unsigned char byte2 = this->readByte();
        
        value |= (byte1 << 8 | byte2 << 0);
        
        return value;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
int DataInputStream::readInt() throw ( io::IOException, io::EOFException ) {
    try {

        unsigned int value = 0;

        unsigned char byte1 = this->readByte();
        unsigned char byte2 = this->readByte();
        unsigned char byte3 = this->readByte();
        unsigned char byte4 = this->readByte();
        
        value |= (byte1 << 24 | byte2 << 16 | byte3 << 8 | byte4 << 0);
        
        return value;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
double DataInputStream::readDouble() throw ( io::IOException, io::EOFException ) {
    try {

        unsigned long long lvalue = this->readLong();
        double value = 0.0;
        memcpy( &value, &lvalue, sizeof( unsigned long long ) );        
        return value;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
float DataInputStream::readFloat() throw ( io::IOException, io::EOFException ) {
    try {

        unsigned int lvalue = this->readInt();
        float value = 0.0f;
        memcpy( &value, &lvalue, sizeof( unsigned int ) );
        return value;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
long long DataInputStream::readLong()
    throw ( io::IOException, io::EOFException ) {
    try {

        unsigned long long value = 0;

        unsigned long long byte1 = this->readByte() & 0x00000000000000FFULL;
        unsigned long long byte2 = this->readByte() & 0x00000000000000FFULL;
        unsigned long long byte3 = this->readByte() & 0x00000000000000FFULL;
        unsigned long long byte4 = this->readByte() & 0x00000000000000FFULL;
        unsigned long long byte5 = this->readByte() & 0x00000000000000FFULL;
        unsigned long long byte6 = this->readByte() & 0x00000000000000FFULL;
        unsigned long long byte7 = this->readByte() & 0x00000000000000FFULL;
        unsigned long long byte8 = this->readByte() & 0x00000000000000FFULL;

        value = ( byte1 << 56 | byte2 << 48 | byte3 << 40 | byte4 << 32 |
                  byte5 << 24 | byte6 << 16 | byte7 << 8  | byte8 << 0 );

        return value;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
std::string DataInputStream::readString() 
    throw ( io::IOException, io::EOFException ) {
    try {
        std::string retVal;
        char temp = 0;
        
        while( true ){
            temp = readChar();
            
            // if null is found we are done.
            if( temp == '\0' ){
                break;
            }
            
            // Append no matter what
            retVal += temp;            
        }
        
        return retVal;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )    
}

////////////////////////////////////////////////////////////////////////////////
std::string DataInputStream::readUTF() 
    throw ( io::IOException, io::EOFException ) {
    try {
        std::string buffer;
        unsigned short len = readUnsignedShort();
        buffer.resize(len);
        readFully( (unsigned char*)buffer.c_str(), 0, len );
        return buffer;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )    
}

////////////////////////////////////////////////////////////////////////////////
void DataInputStream::readFully( std::vector< unsigned char >& buffer ) 
    throw ( io::IOException, io::EOFException ) {
    try {
        this->readFully( &buffer[0], 0, buffer.size() );
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}

////////////////////////////////////////////////////////////////////////////////
void DataInputStream::readFully( unsigned char* buffer, int offset, int length ) 
    throw ( io::IOException, io::EOFException, exceptions::IndexOutOfBoundsException, exceptions::NullPointerException ) {
    try {
        if( length < 0 || offset < 0 ) {
            throw IndexOutOfBoundsException(
                __FILE__, __LINE__,
                "DataInputStream::readFully - Len or Offset were invalid" );
        }
        
        if( buffer == NULL ) {
            throw NullPointerException( 
                __FILE__, __LINE__,
                "DataInputStream::read - Buffer is null" );
        }
    
        int n = 0;
        while( n < length ) {
            int count = inputStream->read( &buffer[offset + n], length - n );
            if( count < 0 ) {
                throw EOFException(
                    __FILE__, __LINE__,
                    "DataInputStream::readFully - Reached EOF" );
            }
            n += count;
        }
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )    
}

////////////////////////////////////////////////////////////////////////////////
int DataInputStream::skipBytes( int num ) throw( io::IOException ) {
    try {
        int total = 0;
        int cur = 0;

        while( ( total < num ) && 
               ( ( cur = (int)inputStream->skip( num-total ) ) > 0 ) ) {
            total += cur;
        }

        return total;
    }
    AMQ_CATCH_RETHROW( IOException )
    AMQ_CATCHALL_THROW( IOException )
}
