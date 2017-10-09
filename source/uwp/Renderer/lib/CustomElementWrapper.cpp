#include "pch.h"
#include "CustomElementWrapper.h"

using namespace Microsoft::WRL;
using namespace ABI::AdaptiveCards::Uwp;

namespace AdaptiveCards { namespace Uwp
{

bool CustomElementWrapper::GetSeparator() const
{
    boolean hasSeparator;
    THROW_IF_FAILED(m_cardElement->get_Separator(&hasSeparator));
    return hasSeparator;
}

void CustomElementWrapper::SetSeparator(const bool value)
{
    THROW_IF_FAILED(m_cardElement->put_Separator(value));
}

Spacing CustomElementWrapper::GetSpacing() const
{
    ABI::AdaptiveCards::Uwp::Spacing spacing;
    THROW_IF_FAILED(m_cardElement->get_Spacing(&spacing));

    return static_cast<Spacing> (spacing);
}

void CustomElementWrapper::SetSpacing(const Spacing value)
{
    THROW_IF_FAILED(m_cardElement->put_Spacing(static_cast<ABI::AdaptiveCards::Uwp::Spacing>(value)));
}

std::string CustomElementWrapper::GetId() const
{
    HSTRING id; //BECKYTODO - memory management?
    THROW_IF_FAILED(m_cardElement->get_Id(&id));
    return HStringToUTF8(id);
}

void CustomElementWrapper::SetId(const std::string value)
{
    HSTRING id; //BECKYTODO - memory management?
    THROW_IF_FAILED(UTF8ToHString(value, &id));
    THROW_IF_FAILED(m_cardElement->put_Id(id));
}

const CardElementType CustomElementWrapper::GetElementType() const
{
    ABI::AdaptiveCards::Uwp::ElementType elementType;
    THROW_IF_FAILED(m_cardElement->get_ElementType(&elementType));
    return static_cast<CardElementType>(elementType);
}
std::string CustomElementWrapper::Serialize()
{
    return std::string(); //BECKYTODO
}
}}
