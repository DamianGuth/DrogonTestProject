#include "TestCtrl.h"
void TestCtrl::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    //write your application logic here
    auto resp=HttpResponse::newHttpResponse();

    resp->setStatusCode(k200OK);
    resp->setContentTypeCode(CT_TEXT_HTML);
    resp->setBody("Hello world from drogon controller!");

    auto cookieText = req->getCookie("test");

    LOG_DEBUG<<"Data "<<cookieText<<" received";

    if(cookieText == "value")
      resp->addCookie("test", "HAD COOKIE BEFORE");
    else
      resp->addCookie("test", "value");

    callback(resp);
}
