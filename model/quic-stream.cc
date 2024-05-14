/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2019 SIGNET Lab, Department of Information Engineering, University of Padova
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Authors: Alvise De Biasio <alvise.debiasio@gmail.com>
 *          Federico Chiariotti <chiariotti.federico@gmail.com>
 *          Michele Polese <michele.polese@gmail.com>
 *          Davide Marcato <davidemarcato@outlook.com>
 *
 */

#define __STDC_LIMIT_MACROS

#include "ns3/object.h"
#include "ns3/log.h"
#include "ns3/uinteger.h"
#include "ns3/double.h"
#include "ns3/boolean.h"
#include "ns3/trace-source-accessor.h"
#include "ns3/nstime.h"
#include "quic-stream.h"
#include "ns3/node.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("QuicStream");

NS_OBJECT_ENSURE_REGISTERED (QuicStream);

TypeId
QuicStream::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::QuicStream")
    .SetParent<Object> ()
    .SetGroupName ("Internet")
  ;
  return tid;
}

QuicStream::QuicStream ()
  : Object ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

QuicStream::~QuicStream ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

std::ostream&
operator<<(std::ostream& os, QuicStream::Direction direction)
{
  switch (direction)
  {
  case QuicStream::Direction::SENDER:
      return os << "SENDER";
  case QuicStream::Direction::RECEIVER:
      return os << "RECEIVER";
  case QuicStream::Direction::BIDIRECTIONAL:
      return os << "BIDIRECTIONAL";
  case QuicStream::Direction::UNKNOWN:
      return os << "UNKNOWN";
  };
  return os << "UNKNOWN(" << static_cast<uint32_t>(direction) << ")";
}

std::ostream&
operator<<(std::ostream& os, QuicStream::State state)
{
  switch (state)
  {
  case QuicStream::State::IDLE:
      return os << "IDLE";
  case QuicStream::State::OPEN:
      return os << "OPEN";
  case QuicStream::State::SEND:
      return os << "SEND";
  case QuicStream::State::RECV:
      return os << "RECV";
  case QuicStream::State::SIZE_KNOWN:
      return os << "SIZE_KNOWN";
  case QuicStream::State::DATA_SENT:
      return os << "DATA_SENT";
  case QuicStream::State::DATA_RECVD:
      return os << "DATA_RECVD";
  case QuicStream::State::DATA_READ:
      return os << "DATA_READ";
  case QuicStream::State::RESET_SENT:
      return os << "RESET_SENT";
  case QuicStream::State::RESET_RECVD:
      return os << "RESET_RECVD";
  case QuicStream::State::RESET_READ:
      return os << "RESET_READ";
  };
  return os << "UNKNOWN(" << static_cast<uint32_t>(state) << ")";
}

} // namespace ns3
