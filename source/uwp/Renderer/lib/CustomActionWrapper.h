#pragma once

#include "AdaptiveCards.Uwp.h"
#include "Util.h"

namespace AdaptiveCards { namespace Uwp
{
    class CustomActionWrapper : public AdaptiveCards::BaseActionElement
    {
    public:
        CustomActionWrapper(ABI::AdaptiveCards::Uwp::IAdaptiveActionElement* actionElement):
            BaseActionElement(AdaptiveCards::ActionType::Custom),
            m_actionElement(actionElement)
        {}

        std::string GetId() const override;
        void SetId(const std::string value) override;

        std::string GetTitle() const override;
        void SetTitle(const std::string value) override;

        const ActionType GetElementType() const override;

        virtual std::string Serialize() override;

    private:
        Microsoft::WRL::ComPtr<ABI::AdaptiveCards::Uwp::IAdaptiveActionElement> m_actionElement;
    };
}}
