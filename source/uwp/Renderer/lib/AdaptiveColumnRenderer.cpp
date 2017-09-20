#include "pch.h"

#include "AdaptiveColumnRenderer.h"
#include "enums.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::XamlCardRenderer;
using namespace ABI::Windows::Foundation;

namespace AdaptiveCards { namespace XamlCardRenderer
{
    HRESULT AdaptiveColumnRenderer::RuntimeClassInitialize() noexcept try
    {
        return S_OK;
    } CATCH_RETURN;


    _Use_decl_annotations_
    HRESULT AdaptiveColumnRenderer::Render(
        IAdaptiveCardElement* cardElement,
        IAdaptiveRenderContext* renderContext,
        ABI::Windows::UI::Xaml::IUIElement** result)
    {
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColumnRenderer::get_Type(HSTRING* type)
    {
        return UTF8ToHString(CardElementTypeToString(CardElementType::Column), type);
    }
}}
