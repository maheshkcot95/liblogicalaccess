/**
* \file mifarenfctagcardservice.hpp
* \author Maxime C. <maxime-dev@islog.com>
* \brief Mifare Classic NFC Tag card service.
*/

#ifndef LOGICALACCESS_MIFARENFCTAGCARDSERVICE_HPP
#define LOGICALACCESS_MIFARENFCTAGCARDSERVICE_HPP

#include "logicalaccess/services/nfctag/nfctagcardservice.hpp"
#include "logicalaccess/services/nfctag/ndefmessage.hpp"
#include "mifarechip.hpp"

namespace logicalaccess
{
    /**
    * \brief The Mifare Classic NFC Tag storage card service base class.
    */
    class LIBLOGICALACCESS_API MifareNFCTagCardService : public NFCTagCardService
    {
    public:

        /**
        * \brief Constructor.
        * \param chip The chip.
        */
	    explicit MifareNFCTagCardService(std::shared_ptr<Chip> chip) : NFCTagCardService(chip) {}

        virtual ~MifareNFCTagCardService() {}

	    std::shared_ptr<NdefMessage> readNDEF() override;

	    void writeNDEF(std::shared_ptr<NdefMessage> records) override;

	    void eraseNDEF() override;

    protected:

        std::shared_ptr<MifareChip> getMifareChip() const { return std::dynamic_pointer_cast<MifareChip>(getChip()); }
    };
}

#endif /* LOGICALACCESS_MIFARENFCTAGCARDSERVICE_HPP */