/*
 * ppscontrol.h
 *
 *  Created on: Jun 21, 2021
 *      Author: uidq3210
 */

#ifndef PPSCONTROL_H_
#define PPSCONTROL_H_

#include <functional>

#ifndef USING_DEY_NAMESPACE
	#define USING_DEY_NAMESPACE using namespace DESY;
#endif

namespace DESY {

typedef	enum MSGTYPE_DEFINE
{
	MSGTYPE_BEST_EFFORT		= 0,
	MSGTYPE_RELIABLE		= 1
}MSGTYPE_DEFINE_ENUM;

typedef	enum INDEPENDENT_DEFINE
{
	USE_SHARED_THREAD		= 0,
	USE_INDEPENDENT_THREAD	= 1
}INDEPENDENT_DEFINE_ENUM;

typedef	enum SUBSCRIBER_DEFINE
{
	SUBS_DISABLE		= 0,	// 不订阅
	SUBS_OPENREAD		= 1,	// 订阅时读历史数据
	SUBS_OPENTRUNC		= 2		// 订阅时不读历史数据
}SUBSCRIBER_DEFINE_ENUM;

typedef void (*message_callback_fun)(int topicid,int cmdid,int size,char *pdata);

typedef std::function<void (int topicid,int cmdid,int size,char *pdata)> message_callback_std;

typedef struct PPS_CFG //base support.
{
	int				topicid;
	char 			topicname[32];
	int				bufcnt;//max buffer cnt of one cmd.
	int				issub;// is sub?
	int				ispub;// is pub?
	int				cmdcnt;//max cmd count
	int				datasize;//max cmd data size;
}PPS_CFG_STRU;

typedef struct PPS_CFG_EX //support independent_thread and priority.
{
	int				topicid;
	char 			topicname[32];
	int				bufcnt;//max buffer cnt of one cmd.
	int				issub;// is sub?
	int				ispub;// is pub?
	int				cmdcnt;//max cmd count
	int				datasize;//max cmd data size;
	int				independent_thread;
	int				priority;

}PPS_CFG_EX_STRU;

typedef struct PPS_CFG_EXX //support function safety msgtype.
{
	int				topicid;
	char 			topicname[32];
	int				bufcnt;//max buffer cnt of one cmd.
	int				issub;// is sub?
	int				ispub;// is pub?
	int				cmdcnt;//max cmd count
	int				datasize;//max cmd data size;
	int				independent_thread;
	int				priority;
	int				msgtype;//0:besteffort msg  1:reliable msg
}PPS_CFG_EXX_STRU;

class HalSubInterface {
public:
  virtual void onHalSubInterface(int topicid,int cmdid,int size,char *pdata) = 0;
};

class ppscontrol
{
public:
    static ppscontrol* Instance();//just get handle
	static ppscontrol* Instance(PPS_CFG_STRU *ppscfg,int size);//create and get handle
	static ppscontrol* Instance(PPS_CFG_EX_STRU *ppscfg,int size);//create and get handle
	static ppscontrol* Instance(PPS_CFG_EXX_STRU *ppscfg,int size);//create and get handle

	void registerCallback(message_callback_fun pcallback);//register static receive callback.
	void registerCallback(message_callback_std pcallback);//register std:function callback.
	void registerCallback(HalSubInterface* data_receiver);//register interface receive callback.
	bool publish(int topic,int cmdid,int size,char *data);//send message.

	bool subscribe(int topicid,int stat);					// 订阅与取消订阅接口

private:
	static ppscontrol* instance;
    ppscontrol();
    ppscontrol(PPS_CFG_STRU *ppscfg,int size);
    ppscontrol(PPS_CFG_EX_STRU *ppscfg,int size);
    ppscontrol(PPS_CFG_EXX_STRU *ppscfg,int size);

	~ppscontrol();

	class ppscontrolImpl;

private:
    ppscontrolImpl * _pimpl;
};

}//end namesapce

#endif /* PPSCONTROL_H_ */
