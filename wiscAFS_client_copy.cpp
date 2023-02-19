#include "./wiscAFS_client.h"
int main(int argc, char **argv)
{
    string hostport;
    if (argc > 1)
    {
        hostport = argv[1];
    }
    else
        hostport = "localhost:50051";
    WiscAFSClient clinet(grpc::CreateChannel(hostport, grpc::InsecureChannelCredentials()));

    //============ For Testing=========
    std::string user("distributed systems");
    std::string reply = clinet.SayHello(user);
    std::cout << "Greeter received: " << reply << std::endl;
    return 0;
}
