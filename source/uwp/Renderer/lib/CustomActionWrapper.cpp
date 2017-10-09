#include "pch.h"
#include "CustomActionWrapper.h"

using namespace Microsoft::WRL;
using namespace ABI::AdaptiveCards::Uwp;

namespace AdaptiveCards { namespace Uwp
{

std::string CustomActionWrapper::GetId() const
{
    HSTRING id; //BECKYTODO - memory management?
    THROW_IF_FAILED(m_actionElement->get_Id(&id));
    return HStringToUTF8(id);
}

void CustomActionWrapper::SetId(const std::string value)
{
    HSTRING id; //BECKYTODO - memory management?
    THROW_IF_FAILED(UTF8ToHString(value, &id));
    THROW_IF_FAILED(m_actionElement->put_Id(id));
}

std::string CustomActionWrapper::GetTitle() const
{
    HSTRING title; //BECKYTODO - memory management?
    THROW_IF_FAILED(m_actionElement->get_Title(&title));
    return HStringToUTF8(title);
}

void CustomActionWrapper::SetTitle(const std::string value)
{
    HSTRING title; //BECKYTODO - memory management?
    THROW_IF_FAILED(UTF8ToHString(value, &title));
    THROW_IF_FAILED(m_actionElement->put_Title(title));
}

const ActionType CustomActionWrapper::GetElementType() const
{
    ABI::AdaptiveCards::Uwp::ActionType actionType;
    THROW_IF_FAILED(m_actionElement->get_ActionType(&actionType));
    return static_cast<ActionType>(actionType);
}
std::string CustomActionWrapper::Serialize()
{
    return std::string(); //BECKYTODO
}
}}
