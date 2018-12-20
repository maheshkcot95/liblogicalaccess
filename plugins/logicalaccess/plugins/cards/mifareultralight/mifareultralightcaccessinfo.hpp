/**
 * \file mifareultralightcaccessinfo.hpp
 * \author Maxime C. <maxime-dev@islog.com>
 * \brief Mifare Ultralight C AccessInfo.
 */

#ifndef LOGICALACCESS_MIFAREULTRALIGHTCACCESSINFO_HPP
#define LOGICALACCESS_MIFAREULTRALIGHTCACCESSINFO_HPP

#include <logicalaccess/plugins/cards/mifareultralight/mifareultralightaccessinfo.hpp>
#include <logicalaccess/cards/tripledeskey.hpp>

namespace logicalaccess
{
/**
 * \brief A Mifare Ultralight C access informations.
 */
class LLA_CARDS_MIFAREULTRALIGHT_API MifareUltralightCAccessInfo
    : public MifareUltralightAccessInfo
{
  public:
#ifndef SWIG
    using XmlSerializable::serialize;
    using XmlSerializable::unSerialize;
#else
    /**
     * \brief Serialize object to Xml Node string.
     * \return The serialized object.
     */
    virtual std::string serialize();

    /**
     * \brief UnSerialize object from a Xml Node string.
     * \param xmlstring The Xml Node string.
     * \param rootNode The root node.
     * \return True on success, false otherwise.
     */
    virtual void unSerialize(const std::string &xmlstring, const std::string &rootNode);

    /**
     * \brief UnSerialize object from a Xml node.
     * \param is The Xml stream.
     * \param rootNode The root node.
     * \return True on success, false otherwise.
     */
    virtual void unSerialize(std::istream &is, const std::string &rootNode);

    /**
     * \brief UnSerialize object from a Xml node.
     * \param node The Xml node.
     * \param rootNode The root node.
     * \return True on success, false otherwise.
     */
    virtual void unSerialize(boost::property_tree::ptree &node,
                             const std::string &rootNode);
#endif

    /**
     * \brief Constructor.
     */
    MifareUltralightCAccessInfo();

    /**
     * \brief Destructor.
     */
    virtual ~MifareUltralightCAccessInfo();

    /**
     * \brief Generate pseudo-random Mifare Ultralight C access informations.
     */
    void generateInfos() override;

    /**
     * \brief Get the card type for this access infos.
     * \return The card type.
     */
    std::string getCardType() const override;

    /**
     * \brief Serialize the current object to XML.
     * \param parentNode The parent node.
     */
    void serialize(boost::property_tree::ptree &parentNode) override;

    /**
     * \brief UnSerialize a XML node to the current object.
     * \param node The XML node.
     */
    void unSerialize(boost::property_tree::ptree &node) override;

    /**
     * \brief Get the default Xml Node name for this object.
     * \return The Xml node name.
     */
    std::string getDefaultXmlNodeName() const override;

    /**
     * \brief Equality operator
     * \param ai Access infos to compare.
     * \return True if equals, false otherwise.
     */
    bool operator==(const AccessInfo &ai) const override;

    /**
 * \brief The authentication key.
 */
    std::shared_ptr<TripleDESKey> key;
};
}

#endif /* LOGICALACCESS_MIFAREULTRALIGHTCACCESSINFO_H */