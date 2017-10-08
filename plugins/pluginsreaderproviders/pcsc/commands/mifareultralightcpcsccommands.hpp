/**
 * \file mifareultralightcpcsccommands.hpp
 * \author Maxime C. <maxime-dev@islog.com>
 * \brief Mifare Ultralight C pcsc card.
 */

#ifndef LOGICALACCESS_MIFAREULTRALIGHTCPCSCCOMMANDS_HPP
#define LOGICALACCESS_MIFAREULTRALIGHTCPCSCCOMMANDS_HPP

#include "mifareultralightpcsccommands.hpp"
#include "mifareultralight/mifareultralightccommands.hpp"

namespace logicalaccess
{
    /**
     * \brief The Mifare Ultralight C commands class for PCSC reader.
     */
    class LIBLOGICALACCESS_API MifareUltralightCPCSCCommands : public MifareUltralightPCSCCommands, public MifareUltralightCCommands
    {
    public:

        /**
         * \brief Constructor.
         */
        MifareUltralightCPCSCCommands();

        /**
         * \brief Destructor.
         */
        virtual ~MifareUltralightCPCSCCommands();

        /**
         * \brief Authenticate to the chip.
         * \param authkey The authentication key.
         */
	    void authenticate(std::shared_ptr<TripleDESKey> authkey) override;

    protected:

		virtual void startGenericSession();

		virtual void stopGenericSession();

		std::shared_ptr<MifareUltralightChip> getMifareUltralightChip() override;

		void writePage(int page, const ByteVector& buf) override;

        virtual ByteVector sendGenericCommand(const ByteVector& data);

        virtual ByteVector authenticate_PICC1();

        virtual ByteVector authenticate_PICC2(const ByteVector& encRndAB);
    };
}

#endif /* LOGICALACCESS_MIFAREULTRALIGHTCPCSCCOMMANDS_HPP */