#include "mage_packet.h"


// �޸� Ǯ
MPool<MMemory> MPacket::MemoryPool;



//-----------------------------------------------------------
// MPacketConnectResponse
//-----------------------------------------------------------
void MPacketConnectResponse::Serialize(MStream& inStream)
{
	inStream.Process(&Error, sizeof(Error));
}

