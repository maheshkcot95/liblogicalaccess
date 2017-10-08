#include "logicalaccess/iks/IslogKeyServer.hpp"

using namespace logicalaccess;
using namespace iks;

void test_aes_encrypt_decrypt()
{
    IslogKeyServer &srv = IslogKeyServer::fromGlobalSettings();

    auto v         = std::vector<uint8_t>(16, 'a');
    auto iv        = std::array<uint8_t, 16>{ {0} };
    auto encrypted = srv.aes_encrypt(v, "imported-aes-key", iv);
    auto decrypted = srv.aes_decrypt(encrypted, "imported-aes-key", iv);

    assert(v == decrypted);
}

void test_des_encrypt_decrypt()
{
    IslogKeyServer &srv = IslogKeyServer::fromGlobalSettings();

    auto v         = std::vector<uint8_t>(8, 'a');
    auto iv        = std::array<uint8_t, 8>{ {0} };
    auto encrypted = srv.des_cbc_encrypt(v, "imported-zero-des", iv);
    auto decrypted = srv.des_cbc_decrypt(encrypted, "imported-zero-des", iv);

    assert(v == decrypted);
    auto expected =
        std::vector<uint8_t>{0xf9, 0x0a, 0xba, 0x97, 0x69, 0x00c, 0xaf, 0x10};
    assert(encrypted == expected);

    // Again, with other values.
    v         = std::vector<uint8_t>(80, 'b');
    iv        = std::array<uint8_t, 8>{ {66, 66, 66, 66, 66, 66, 66, 66} };
    encrypted = srv.des_cbc_encrypt(v, "imported-zero-des", iv);
    decrypted = srv.des_cbc_decrypt(encrypted, "imported-zero-des", iv);

    assert(v == decrypted);
    expected = std::vector<uint8_t>{
        0xcf, 0x95, 0xbe, 0x9c, 0x37, 0x89, 0xb5, 0xe3, 0x35, 0xf6, 0xd4, 0x58,
        0xb5, 0x5c, 0x7a, 0x91, 0x7a, 0x7a, 0x28, 0x0b, 0xc4, 0xbc, 0xd6, 0x4d,
        0xac, 0x87, 0x12, 0x7b, 0x5b, 0xae, 0x20, 0xdb, 0xaf, 0x7d, 0x0f, 0xb8,
        0xbe, 0xb4, 0x4d, 0x52, 0xa3, 0x22, 0x71, 0x0d, 0x7d, 0xb3, 0xbb, 0xf8,
        0x08, 0xce, 0x2b, 0x21, 0xa0, 0xc7, 0x3a, 0xe2, 0xe5, 0x02, 0xa4, 0x8f,
        0x4e, 0xee, 0x0a, 0x70, 0xf6, 0x37, 0x1a, 0x0d, 0x3b, 0x69, 0x9d, 0x09,
        0x4d, 0x8e, 0xf7, 0x44, 0x9f, 0xfd, 0xe3, 0x9a};
    assert(encrypted == expected);

    // Again, using ECB this time.
    v         = std::vector<uint8_t>(80, 'b');
    iv        = std::array<uint8_t, 8>{ {66, 66, 66, 66, 66, 66, 66, 66} };
    encrypted = srv.des_ecb_encrypt(v, "imported-zero-des", iv);
    decrypted = srv.des_ecb_decrypt(encrypted, "imported-zero-des", iv);

    assert(v == decrypted);
    expected = {0x04, 0x5d, 0xca, 0xc6, 0xb3, 0xda, 0x0a, 0xa2, 0x04, 0x5d,
                0xca, 0xc6, 0xb3, 0xda, 0x0a, 0xa2, 0x04, 0x5d, 0xca, 0xc6,
                0xb3, 0xda, 0x0a, 0xa2, 0x04, 0x5d, 0xca, 0xc6, 0xb3, 0xda,
                0x0a, 0xa2, 0x04, 0x5d, 0xca, 0xc6, 0xb3, 0xda, 0x0a, 0xa2,
                0x04, 0x5d, 0xca, 0xc6, 0xb3, 0xda, 0x0a, 0xa2, 0x04, 0x5d,
                0xca, 0xc6, 0xb3, 0xda, 0x0a, 0xa2, 0x04, 0x5d, 0xca, 0xc6,
                0xb3, 0xda, 0x0a, 0xa2, 0x04, 0x5d, 0xca, 0xc6, 0xb3, 0xda,
                0x0a, 0xa2, 0x04, 0x5d, 0xca, 0xc6, 0xb3, 0xda, 0x0a, 0xa2};
    assert(encrypted == expected);
}

int main()
{
    IslogKeyServer &srv = IslogKeyServer::fromGlobalSettings();

    srv.get_random(17);

    test_aes_encrypt_decrypt();
    test_des_encrypt_decrypt();
}
