#pragma once

#include "mage_network.h"
#include "mage_buffer.h"
#include "mage_io_model_iocp_message.h"

#include <atomic>
#include <mutex>



//-------------------------------------------------------------
// IOCP ��������
//-------------------------------------------------------------
class MIOCPSocket : public MSocket
{
public:
	MIOCPSocket(MINDEX inIndex);
	virtual ~MIOCPSocket();

public:
	// IOCP �ڵ� ����
	void SetIOCP(HANDLE inIOCP) {
		IOCP = inIOCP;
	}

	// ����
	void Update();

	//-----------------------------------------------------
	// �������̽�
	//-----------------------------------------------------
	// Accept ����
	void Accept();

	// recv����
	void Recv();

	// ����
	void Send(const MBYTE* inData, MSIZE inSize);

	
	//-----------------------------------------------------
	// �������� 
	//-----------------------------------------------------
	// ���� ��Ŷ �߰�
	void PushSendPacket(MUINT32 inPacketID, class MPacket& inPacket, MMemory* inTempMemory);

	// ���� ó��
	void SendBufferData();

	
	// 
	void PushRecvPacket(void* inData, MSIZE inSize);


	MBuffer* GetRecvBuffer() const {
		return RecvBuffer;
	}

protected:
	HANDLE IOCP = NULL;

	// �۽� ����
	MBuffer* SendPushBuffer = nullptr;
	MBuffer* SendBuffer = nullptr;

	// ���� �÷���
	std::atomic<bool> SendFlag = false;

	//---------------------------------------------------------
	// ����ó��
	//---------------------------------------------------------
	MBuffer* RecvPushBuffer = nullptr;
	MBuffer* RecvBuffer = nullptr;

	std::atomic<bool> RecvFlag = false;

	
	//-----------------------------------------------------------
	// ��û �޽���
	//-----------------------------------------------------------
	// ��Ŷ ���� �޽���
	MIOCPRequestSendMessage RequestSendMessage;

	//-----------------------------------------------------------
	// �Ϸ� �޽���
	//-----------------------------------------------------------
	// Accept �Ϸ� �޽���
	MIOCPCompletionAcceptMessage CompletionAcceptMessage;

	// Recv �Ϸ� �޽���
	MIOCPCompletionRecvMessage CompletionRecvMessage;

	// Send �Ϸ� �޽���
	MIOCPCompletionSendMessage CompletionSendMessage;
};
