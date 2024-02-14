#pragma once



#include "mage_network.h"
#include <thread>
#include <mutex>

#include "mage_buffer.h"
#include "mage_memory.h"

#if (MPLATFORM == MPLATFORM_WINDOWS)


//-------------------------------------------------------------
// IOCP �۾� ������
//-------------------------------------------------------------
class MIOModelIOCPWorkerThread
{
public:
	MIOModelIOCPWorkerThread(class MIOModelIOCP* inOwner);
	~MIOModelIOCPWorkerThread();

public:
	void Run();
	void Stop();

protected:
	// ���� ó��
	void Update();


	//-------------------------------------------------------------
	// �� �޽��� ó��
	//-------------------------------------------------------------
	// accpet �Ϸ� �޽���
	void ProcessCompletionAcceptMessage(struct MIOCPCompletionAcceptMessage* inMessage);

	// recv �Ϸ� �޽���
	void ProcessCompletionRecvMessage(struct MIOCPCompletionRecvMessage* inMessage, DWORD inSize);

protected:
	// ������
	class MIOModelIOCP* Owner = nullptr;

	// IOCP ��ü
	HANDLE IOCP;

	// ������ ��ü
	std::thread WorkerThread;

	// �ӽ� ����
	MBuffer TempBuffer;
	MMemory TempMemory;
};


#endif
