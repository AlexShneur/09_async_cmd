#include <iostream>
#include "async.h"

int main(int argc, const char* argv[])
{
    std::size_t bulk_size = 3;

    auto h_static = async::connect(bulk_size);
    std::string test_static = "cmd1\ncmd2\ncmd3\ncmd4\ncmd5\nEOF\n";
    async::receive(h_static, test_static.c_str(), test_static.size());

    auto h_dynamic = async::connect(bulk_size);
    std::string test_dynamic = "cmd1\ncmd2\n{\ncmd3\ncmd4\n}\n{\ncmd5\ncmd6\n{\ncmd7\ncmd8\n}\ncmd9\n}\n{\ncmd10\ncmd11\nEOF\n";
    async::receive(h_dynamic, test_dynamic.c_str(), test_dynamic.size());

    async::disconnect(h_static);
    async::disconnect(h_dynamic);

    return 0;
}
