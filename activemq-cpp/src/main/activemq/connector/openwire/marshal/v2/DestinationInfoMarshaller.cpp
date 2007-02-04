/*
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.
 * The ASF licenses this file to You under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <activemq/connector/openwire/marshal/v2/DestinationInfoMarshaller.h>

#include <activemq/connector/openwire/commands/DestinationInfo.h>

//
//     NOTE!: This file is autogenerated - do not modify!
//            if you need to make a change, please see the Java Classes in the
//            activemq-core module
//

using namespace std;
using namespace activemq;
using namespace activemq::io;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;
using namespace activemq::connector::openwire::marshal;
using namespace activemq::connector::openwire::utils;
using namespace activemq::connector::openwire::marshal::v2;

///////////////////////////////////////////////////////////////////////////////
DataStructure* DestinationInfoMarshaller::createObject() const {
    return new DestinationInfo();
}

///////////////////////////////////////////////////////////////////////////////
unsigned char DestinationInfoMarshaller::getDataStructureType() const {
    return DestinationInfo::ID_DESTINATIONINFO;
}

///////////////////////////////////////////////////////////////////////////////
void DestinationInfoMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    DestinationInfo* info =
        dynamic_cast<DestinationInfo*>( dataStructure );
    info->setConnectionId( dynamic_cast< ConnectionId* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setDestination( dynamic_cast< ActiveMQDestination* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setOperationType( dataIn->readByte() );
    info->setTimeout( tightUnmarshalLong( wireFormat, dataIn, bs ) );

    if( bs->readBoolean() ) {
        short size = dataIn->readShort();
        info->getBrokerPath().reserve( size );
        for( int i = 0; i < size; i++ ) {
            info->getBrokerPath().push_back( dynamic_cast< BrokerId* >(
                tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) );
        }
    }
    else {
        info->getBrokerPath().clear();
    }
}

///////////////////////////////////////////////////////////////////////////////
int DestinationInfoMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ) {

    DestinationInfo* info =
        dynamic_cast<DestinationInfo*>( dataStructure );

    int rc = BaseCommandMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getConnectionId(), bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getDestination(), bs );
    rc += tightMarshalLong1( wireFormat, info->getTimeout(), bs );
    rc += tightMarshalObjectArray1( wireFormat, info->getBrokerPath(), bs );

    return rc + 1;
}

///////////////////////////////////////////////////////////////////////////////
void DestinationInfoMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    DestinationInfo* info =
        dynamic_cast<DestinationInfo*>( dataStructure );
    tightMarshalCachedObject2( wireFormat, info->getConnectionId(), dataOut, bs );
    tightMarshalCachedObject2( wireFormat, info->getDestination(), dataOut, bs );
    dataOut->write( info->getOperationType() );
    tightMarshalLong2( wireFormat, info->getTimeout(), dataOut, bs );
    tightMarshalObjectArray2( wireFormat, info->getBrokerPath(), dataOut, bs );
}

///////////////////////////////////////////////////////////////////////////////
void DestinationInfoMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ) {

    BaseCommandMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    DestinationInfo* info =
        dynamic_cast<DestinationInfo*>( dataStructure );
    info->setConnectionId( dynamic_cast< ConnectionId* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setDestination( dynamic_cast< ActiveMQDestination* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setOperationType( dataIn->readByte() );
    info->setTimeout( looseUnmarshalLong( wireFormat, dataIn ) );

    if( dataIn->readBoolean() ) {
        short size = dataIn->readShort();
        info->getBrokerPath().reserve( size );
        for( int i = 0; i < size; i++ ) {
            info->getBrokerPath().push_back( dynamic_cast<BrokerId* >(
                looseUnmarshalNestedObject( wireFormat, dataIn ) ) );
        }
    }
    else {
        info->getBrokerPath().clear();
    }
}

///////////////////////////////////////////////////////////////////////////////
void DestinationInfoMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ) {

    DestinationInfo* info =
        dynamic_cast<DestinationInfo*>( dataStructure );
    BaseCommandMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    looseMarshalCachedObject( wireFormat, info->getConnectionId(), dataOut );
    looseMarshalCachedObject( wireFormat, info->getDestination(), dataOut );
    dataOut->write( info->getOperationType() );
    looseMarshalLong( wireFormat, info->getTimeout(), dataOut );
    looseMarshalObjectArray( wireFormat, info->getBrokerPath(), dataOut );
}

