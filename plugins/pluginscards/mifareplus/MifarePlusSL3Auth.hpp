#pragma once

#include <logicalaccess/cards/aes128key.hpp>
#include "../mifare/mifareaccessinfo.hpp"

namespace logicalaccess
{

    /**
     * Maintain the authentication state and key
     * for MifarePlus in security level 3.
     */
    class LIBLOGICALACCESS_API MifarePlusSL3Auth
    {
    public:
	    explicit MifarePlusSL3Auth(std::shared_ptr<ReaderCardAdapter> rca);

        bool firstAuthenticate(int sector, std::shared_ptr<AES128Key> key,
                               MifareKeyType type);

        /**
         * Derive KEnc for the session.
         */
        ByteVector deriveKEnc();

        /**
         * Compute the key use for MACing.
         */
        ByteVector deriveKMac();

        ByteVector computeWriteMac(uint8_t command_code, uint16_t block_number, const
        ByteVector &data);

        ByteVector cipherWriteData(const ByteVector &in);

    private:

        bool aes_first_auth_step2();

        bool aes_first_auth_final(const ByteVector &encrypted_data);

        std::shared_ptr<ReaderCardAdapter> rca_;

        // The AES key used for authentication
        ByteVector aes_key_;

        // Random generated by us.
        ByteVector rnd_a_;

        // Random generated by reader.
        ByteVector rnd_b_;

    public:

        ByteVector trans_id_;

        uint16_t write_counter_;
        uint16_t read_counter_;

    };

}
