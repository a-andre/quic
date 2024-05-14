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
#include "quic-socket.h"

namespace ns3 {

NS_LOG_COMPONENT_DEFINE ("QuicSocket");

NS_OBJECT_ENSURE_REGISTERED (QuicSocket);

TypeId
QuicSocket::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::QuicSocket")
    .SetParent<Socket> ()
    .SetGroupName ("Internet")
  ;
  return tid;
}

QuicSocket::QuicSocket ()
  : Socket (),
  m_socketType (Type::NONE)
{
  NS_LOG_FUNCTION_NOARGS ();
}

QuicSocket::QuicSocket (const QuicSocket& sock)
  : Socket (sock),
  m_socketType (sock.m_socketType)
{
  NS_LOG_FUNCTION_NOARGS ();
}

QuicSocket::~QuicSocket ()
{
  NS_LOG_FUNCTION_NOARGS ();
}

QuicSocket::Type
QuicSocket::GetQuicSocketType () const
{
  return m_socketType;
}

void
QuicSocket::SetQuicSocketType (Type m_socketType)
{
  QuicSocket::m_socketType = m_socketType;
}

bool
QuicSocket::CheckVersionNegotiation (uint32_t version)
{
  if (version == QUIC_VERSION_NEGOTIATION)
    {
      return true;
    }
  else if ((version & QUIC_VERSION_NEGOTIATION_PATTERN) == QUIC_VERSION_NEGOTIATION_PATTERN)
    {
      return true;
    }
  else
    {
      return false;
    }
}

std::ostream&
operator<<(std::ostream& os, QuicSocket::State state)
{
    switch (state)
    {
    case QuicSocket::State::IDLE:
        return os << "IDLE";
    case QuicSocket::State::LISTENING:
        return os << "LISTENING";
    case QuicSocket::State::CONNECTING_SVR:
        return os << "CONNECTING_SVR";
    case QuicSocket::State::CONNECTING_CLT:
        return os << "CONNECTING_CLT";
    case QuicSocket::State::OPEN:
        return os << "OPEN";
    case QuicSocket::State::CLOSING:
        return os << "CLOSING";
    };
    return os << "UNKNOWN(" << static_cast<uint32_t>(state) << ")";
}

} // namespace ns3
