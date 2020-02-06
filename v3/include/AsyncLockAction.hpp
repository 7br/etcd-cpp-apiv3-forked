#ifndef __ASYNC_LOCKCTION_HPP__
#define __ASYNC_LOCKACTION_HPP__

#include <grpc++/grpc++.h>
#include "proto/rpc.grpc.pb.h"
#include "v3/include/Action.hpp"
#include "v3/include/AsyncLockResponse.hpp"
#include "etcd/Response.hpp"


using grpc::ClientAsyncResponseReader;
using etcdserverpb::LockRequest;
using etcdserverpb::LockResponse;
using etcdserverpb::UnlockRequest;
using etcdserverpb::UnlockResponse;


namespace etcdv3
{
  class AsyncLockAction : public etcdv3::Action
  {
    public:
      AsyncLockAction(etcdv3::ActionParameters param);
      AsyncLockResponse ParseResponse();
    private:
      LockResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<LockResponse>> response_reader;   
  };

  class AsyncUnlockAction : public etcdv3::Action
  {
    public:
      AsyncUnlockAction(etcdv3::ActionParameters param);
      AsyncUnlockResponse ParseResponse();
    private:
      UnlockResponse reply;
      std::unique_ptr<ClientAsyncResponseReader<UnlockResponse>> response_reader;   
  };
}

#endif