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

#include <activemq/connector/openwire/marshal/v2/MessageMarshaller.h>

#include <activemq/connector/openwire/commands/Message.h>

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
void MessageMarshaller::tightUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightUnmarshal( wireFormat, dataStructure, dataIn, bs );

    Message* info =
        dynamic_cast<Message*>( dataStructure );
    info->setProducerId( dynamic_cast< ProducerId* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setDestination( dynamic_cast< ActiveMQDestination* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setTransactionId( dynamic_cast< TransactionId* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setOriginalDestination( dynamic_cast< ActiveMQDestination* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setMessageId( dynamic_cast< MessageId* >(
        tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) );
    info->setOriginalTransactionId( dynamic_cast< TransactionId* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setGroupID( tightUnmarshalString( dataIn, bs ) );
    info->setGroupSequence( dataIn->readInt() );
    info->setCorrelationId( tightUnmarshalString( dataIn, bs ) );
    info->setPersistent( bs->readBoolean() );
    info->setExpiration( tightUnmarshalLong( wireFormat, dataIn, bs ) );
    info->setPriority( dataIn->readByte() );
    info->setReplyTo( dynamic_cast< ActiveMQDestination* >(
        tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) );
    info->setTimestamp( tightUnmarshalLong( wireFormat, dataIn, bs ) );
    info->setType( tightUnmarshalString( dataIn, bs ) );
    info->setContent( tightUnmarshalByteArray( dataIn, bs ) );
    info->setMarshalledProperties( tightUnmarshalByteArray( dataIn, bs ) );
    info->setDataStructure( dynamic_cast< DataStructure* >(
        tightUnmarshalNestedObject( wireFormat, dataIn, bs ) ) );
    info->setTargetConsumerId( dynamic_cast< ConsumerId* >(
        tightUnmarshalCachedObject( wireFormat, dataIn, bs ) ) );
    info->setCompressed( bs->readBoolean() );
    info->setRedeliveryCounter( dataIn->readInt() );

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
    info->setArrival( tightUnmarshalLong( wireFormat, dataIn, bs ) );
    info->setUserID( tightUnmarshalString( dataIn, bs ) );
    info->setRecievedByDFBridge( bs->readBoolean() );
    info->setDroppable( bs->readBoolean() );
}

///////////////////////////////////////////////////////////////////////////////
int MessageMarshaller::tightMarshal1( OpenWireFormat* wireFormat, DataStructure* dataStructure, BooleanStream* bs ) throw( io::IOException ) {

    Message* info =
        dynamic_cast<Message*>( dataStructure );

    int rc = BaseCommandMarshaller::tightMarshal1( wireFormat, dataStructure, bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getProducerId(), bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getDestination(), bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getTransactionId(), bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getOriginalDestination(), bs );
    rc += tightMarshalNestedObject1( wireFormat, info->getMessageId(), bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getOriginalTransactionId(), bs );
    rc += tightMarshalString1( info->getGroupID(), bs );
    rc += tightMarshalString1( info->getCorrelationId(), bs );
    bs->writeBoolean( info->isPersistent() );
    rc += tightMarshalLong1( wireFormat, info->getExpiration(), bs );
    rc += tightMarshalNestedObject1( wireFormat, info->getReplyTo(), bs );
    rc += tightMarshalLong1( wireFormat, info->getTimestamp(), bs );
    rc += tightMarshalString1( info->getType(), bs );
    bs->writeBoolean( info->getContent().size() != 0 );
    rc += info->getContent().size() == 0 ? 0 : info->getContent().size() + 4;
    bs->writeBoolean( info->getMarshalledProperties().size() != 0 );
    rc += info->getMarshalledProperties().size() == 0 ? 0 : info->getMarshalledProperties().size() + 4;
    rc += tightMarshalNestedObject1( wireFormat, info->getDataStructure(), bs );
    rc += tightMarshalCachedObject1( wireFormat, info->getTargetConsumerId(), bs );
    bs->writeBoolean( info->isCompressed() );
    rc += tightMarshalObjectArray1( wireFormat, info->getBrokerPath(), bs );
    rc += tightMarshalLong1( wireFormat, info->getArrival(), bs );
    rc += tightMarshalString1( info->getUserID(), bs );
    bs->writeBoolean( info->isRecievedByDFBridge() );
    bs->writeBoolean( info->isDroppable() );

    return rc + 9;
}

///////////////////////////////////////////////////////////////////////////////
void MessageMarshaller::tightMarshal2( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut, BooleanStream* bs ) throw( io::IOException ) {

    BaseCommandMarshaller::tightMarshal2( wireFormat, dataStructure, dataOut, bs );

    Message* info =
        dynamic_cast<Message*>( dataStructure );
    tightMarshalCachedObject2( wireFormat, info->getProducerId(), dataOut, bs );
    tightMarshalCachedObject2( wireFormat, info->getDestination(), dataOut, bs );
    tightMarshalCachedObject2( wireFormat, info->getTransactionId(), dataOut, bs );
    tightMarshalCachedObject2( wireFormat, info->getOriginalDestination(), dataOut, bs );
    tightMarshalNestedObject2( wireFormat, info->getMessageId(), dataOut, bs );
    tightMarshalCachedObject2( wireFormat, info->getOriginalTransactionId(), dataOut, bs );
    tightMarshalString2( info->getGroupID(), dataOut, bs );
    dataOut->write( info->getGroupSequence() );
    tightMarshalString2( info->getCorrelationId(), dataOut, bs );
    bs->readBoolean();
    tightMarshalLong2( wireFormat, info->getExpiration(), dataOut, bs );
    dataOut->write( info->getPriority() );
    tightMarshalNestedObject2( wireFormat, info->getReplyTo(), dataOut, bs );
    tightMarshalLong2( wireFormat, info->getTimestamp(), dataOut, bs );
    tightMarshalString2( info->getType(), dataOut, bs );
    if( bs->readBoolean() ) {
        dataOut->write( (int)info->getContent().size() );
        dataOut->write( (const unsigned char*)(&info->getContent()[0]), (int)info->getContent().size() );
    }
    if( bs->readBoolean() ) {
        dataOut->write( (int)info->getMarshalledProperties().size() );
        dataOut->write( (const unsigned char*)(&info->getMarshalledProperties()[0]), (int)info->getMarshalledProperties().size() );
    }
    tightMarshalNestedObject2( wireFormat, info->getDataStructure(), dataOut, bs );
    tightMarshalCachedObject2( wireFormat, info->getTargetConsumerId(), dataOut, bs );
    bs->readBoolean();
    dataOut->write( info->getRedeliveryCounter() );
    tightMarshalObjectArray2( wireFormat, info->getBrokerPath(), dataOut, bs );
    tightMarshalLong2( wireFormat, info->getArrival(), dataOut, bs );
    tightMarshalString2( info->getUserID(), dataOut, bs );
    bs->readBoolean();
    bs->readBoolean();
}

///////////////////////////////////////////////////////////////////////////////
void MessageMarshaller::looseUnmarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataInputStream* dataIn ) throw( io::IOException ) {

    BaseCommandMarshaller::looseUnmarshal( wireFormat, dataStructure, dataIn );
    Message* info =
        dynamic_cast<Message*>( dataStructure );
    info->setProducerId( dynamic_cast< ProducerId* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setDestination( dynamic_cast< ActiveMQDestination* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setTransactionId( dynamic_cast< TransactionId* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setOriginalDestination( dynamic_cast< ActiveMQDestination* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setMessageId( dynamic_cast< MessageId* >( 
        looseUnmarshalNestedObject( wireFormat, dataIn ) ) );
    info->setOriginalTransactionId( dynamic_cast< TransactionId* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setGroupID( looseUnmarshalString( dataIn ) );
    info->setGroupSequence( dataIn->readInt() );
    info->setCorrelationId( looseUnmarshalString( dataIn ) );
    info->setPersistent( dataIn->readBoolean() );
    info->setExpiration( looseUnmarshalLong( wireFormat, dataIn ) );
    info->setPriority( dataIn->readByte() );
    info->setReplyTo( dynamic_cast< ActiveMQDestination* >( 
        looseUnmarshalNestedObject( wireFormat, dataIn ) ) );
    info->setTimestamp( looseUnmarshalLong( wireFormat, dataIn ) );
    info->setType( looseUnmarshalString( dataIn ) );
    info->setContent( looseUnmarshalByteArray( dataIn ) );
    info->setMarshalledProperties( looseUnmarshalByteArray( dataIn ) );
    info->setDataStructure( dynamic_cast< DataStructure* >( 
        looseUnmarshalNestedObject( wireFormat, dataIn ) ) );
    info->setTargetConsumerId( dynamic_cast< ConsumerId* >( 
        looseUnmarshalCachedObject( wireFormat, dataIn ) ) );
    info->setCompressed( dataIn->readBoolean() );
    info->setRedeliveryCounter( dataIn->readInt() );

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
    info->setArrival( looseUnmarshalLong( wireFormat, dataIn ) );
    info->setUserID( looseUnmarshalString( dataIn ) );
    info->setRecievedByDFBridge( dataIn->readBoolean() );
    info->setDroppable( dataIn->readBoolean() );
}

///////////////////////////////////////////////////////////////////////////////
void MessageMarshaller::looseMarshal( OpenWireFormat* wireFormat, DataStructure* dataStructure, DataOutputStream* dataOut ) throw( io::IOException ) {

    Message* info =
        dynamic_cast<Message*>( dataStructure );
    BaseCommandMarshaller::looseMarshal( wireFormat, dataStructure, dataOut );

    looseMarshalCachedObject( wireFormat, info->getProducerId(), dataOut );
    looseMarshalCachedObject( wireFormat, info->getDestination(), dataOut );
    looseMarshalCachedObject( wireFormat, info->getTransactionId(), dataOut );
    looseMarshalCachedObject( wireFormat, info->getOriginalDestination(), dataOut );
    looseMarshalNestedObject( wireFormat, info->getMessageId(), dataOut );
    looseMarshalCachedObject( wireFormat, info->getOriginalTransactionId(), dataOut );
    looseMarshalString( info->getGroupID(), dataOut );
    dataOut->write( info->getGroupSequence() );
    looseMarshalString( info->getCorrelationId(), dataOut );
    dataOut->write( info->isPersistent() );
    looseMarshalLong( wireFormat, info->getExpiration(), dataOut );
    dataOut->write( info->getPriority() );
    looseMarshalNestedObject( wireFormat, info->getReplyTo(), dataOut );
    looseMarshalLong( wireFormat, info->getTimestamp(), dataOut );
    looseMarshalString( info->getType(), dataOut );
    dataOut->write( info->getContent().size() != 0 );
    if( info->getContent().size() != 0 ) {
        dataOut->write( (int)info->getContent().size() );
        dataOut->write( (const unsigned char*)(&info->getContent()[0]), (int)info->getContent().size() );
    }
    dataOut->write( info->getMarshalledProperties().size() != 0 );
    if( info->getMarshalledProperties().size() != 0 ) {
        dataOut->write( (int)info->getMarshalledProperties().size() );
        dataOut->write( (const unsigned char*)(&info->getMarshalledProperties()[0]), (int)info->getMarshalledProperties().size() );
    }
    looseMarshalNestedObject( wireFormat, info->getDataStructure(), dataOut );
    looseMarshalCachedObject( wireFormat, info->getTargetConsumerId(), dataOut );
    dataOut->write( info->isCompressed() );
    dataOut->write( info->getRedeliveryCounter() );
    looseMarshalObjectArray( wireFormat, info->getBrokerPath(), dataOut );
    looseMarshalLong( wireFormat, info->getArrival(), dataOut );
    looseMarshalString( info->getUserID(), dataOut );
    dataOut->write( info->isRecievedByDFBridge() );
    dataOut->write( info->isDroppable() );
}

