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
#include <activemq/connector/openwire/commands/XATransactionId.h>
#include <activemq/exceptions/NullPointerException.h>

using namespace std;
using namespace activemq;
using namespace activemq::exceptions;
using namespace activemq::connector;
using namespace activemq::connector::openwire;
using namespace activemq::connector::openwire::commands;

/*
 *
 *  Command and marshaling code for OpenWire format for XATransactionId
 *
 *
 *  NOTE!: This file is autogenerated - do not modify!
 *         if you need to make a change, please see the Java Classes in the
 *         activemq-core module
 *
 */
////////////////////////////////////////////////////////////////////////////////
XATransactionId::XATransactionId()
{
    this->formatId = 0;
}

////////////////////////////////////////////////////////////////////////////////
XATransactionId::~XATransactionId()
{
}

////////////////////////////////////////////////////////////////////////////////
DataStructure* XATransactionId::cloneDataStructure() const {
    XATransactionId* xATransactionId = new XATransactionId();

    // Copy the data from the base class or classes
    xATransactionId->copyDataStructure( this );

    return xATransactionId;
}

////////////////////////////////////////////////////////////////////////////////
void XATransactionId::copyDataStructure( const DataStructure* src ) {

    // Copy the data of the base class or classes
    TransactionId::copyDataStructure( src );

    const XATransactionId* srcPtr = dynamic_cast<const XATransactionId*>( src );

    if( srcPtr == NULL || src == NULL ) {
    
        throw exceptions::NullPointerException(
            __FILE__, __LINE__,
            "XATransactionId::copyDataStructure - src is NULL or invalid" );
    }
    this->setFormatId( srcPtr->getFormatId() );
    this->setGlobalTransactionId( srcPtr->getGlobalTransactionId() );
    this->setBranchQualifier( srcPtr->getBranchQualifier() );
}

////////////////////////////////////////////////////////////////////////////////
unsigned char XATransactionId::getDataStructureType() const {
    return XATransactionId::ID_XATRANSACTIONID; 
}

////////////////////////////////////////////////////////////////////////////////
int XATransactionId::getFormatId() const {
    return formatId;
}

////////////////////////////////////////////////////////////////////////////////
void XATransactionId::setFormatId(int formatId ) {
    this->formatId = formatId;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<unsigned char>& XATransactionId::getGlobalTransactionId() const {
    return globalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char>& XATransactionId::getGlobalTransactionId() {
    return globalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
void XATransactionId::setGlobalTransactionId(const std::vector<unsigned char>& globalTransactionId ) {
    this->globalTransactionId = globalTransactionId;
}

////////////////////////////////////////////////////////////////////////////////
const std::vector<unsigned char>& XATransactionId::getBranchQualifier() const {
    return branchQualifier;
}

////////////////////////////////////////////////////////////////////////////////
std::vector<unsigned char>& XATransactionId::getBranchQualifier() {
    return branchQualifier;
}

////////////////////////////////////////////////////////////////////////////////
void XATransactionId::setBranchQualifier(const std::vector<unsigned char>& branchQualifier ) {
    this->branchQualifier = branchQualifier;
}

