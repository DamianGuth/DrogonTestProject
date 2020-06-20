#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
namespace demo
{
    namespace v1
    {
        class User:public drogon::HttpController<User>
        {
        public:
            METHOD_LIST_BEGIN
                //use METHOD_ADD to add your custom processing function here;
                METHOD_ADD(User::login,"/token?userId={1}&passwd={2}",Post);
                METHOD_ADD(User::getInfo,"/{1}/info?token={2}",Get);
            METHOD_LIST_END
            //your declaration of processing function maybe like this:
            void login(const HttpRequestPtr &req,
                       std::function<void (const HttpResponsePtr &)> &&callback,
                       std::string &&userId,
                       const std::string &password);
            void getInfo(const HttpRequestPtr &req,
                         std::function<void (const HttpResponsePtr &)> &&callback,
                         std::string userId,
                         const std::string &token) const;
        };
    }
}
