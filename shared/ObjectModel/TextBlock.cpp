#include "TextBlock.h"
#include "ParseUtil.h"

using namespace AdaptiveCards;

TextBlock::TextBlock() : BaseCardElement(CardElementType::TextBlock)
{
}

TextBlock::TextBlock(std::shared_ptr<Container> container,
    HorizontalAlignment horizontalAlignment,
    CardElementSize size,
    std::string speak,
    std::string text,
    TextSize textSize,
    TextWeight textWeight,
    TextColor textColor,
    bool isSubtle,
    bool wrap) :
    BaseCardElement(CardElementType::TextBlock, container, horizontalAlignment, size, speak),
    m_text(text),
    m_textSize(textSize),
    m_textWeight(textWeight),
    m_textColor(textColor),
    m_isSubtle(isSubtle),
    m_wrap(wrap)
{
}

std::shared_ptr<TextBlock> TextBlock::Deserialize(const Json::Value& json)
{
    ParseUtil::ThrowIfNotJsonObject(json);
    ParseUtil::ExpectTypeString(json, CardElementType::TextBlock);

    // Parse base class stuff
    std::string speak = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Speak);
    CardElementSize size = ParseUtil::GetEnumValue<CardElementSize>(json, AdaptiveCardSchemaKey::CardElementSize, CardElementSize::Auto, SizeFromString);
    HorizontalAlignment horAlignment = ParseUtil::GetEnumValue<HorizontalAlignment>(json, AdaptiveCardSchemaKey::HorizontalAlignment, HorizontalAlignment::Left, HorizontalAlignmentFromString);

    // Parse derived class stuff
    std::string text = ParseUtil::GetString(json, AdaptiveCardSchemaKey::Text);
    TextSize textSize = ParseUtil::GetEnumValue<TextSize>(json, AdaptiveCardSchemaKey::TextSize, TextSize::Normal, TextSizeFromString);
    TextColor textColor = ParseUtil::GetEnumValue<TextColor>(json, AdaptiveCardSchemaKey::TextColor, TextColor::Default, TextColorFromString);
    TextWeight textWeight = ParseUtil::GetEnumValue<TextWeight>(json, AdaptiveCardSchemaKey::TextWeight, TextWeight::Normal, TextWeightFromString);
    TextWrap textWrap = ParseUtil::GetEnumValue<TextWrap>(json, AdaptiveCardSchemaKey::TextWrap, TextWrap::NoWrap, TextWrapFromString);

    auto textBlock = std::make_shared<TextBlock>(nullptr, horAlignment, size, speak, text, textSize, textWeight, textColor, false, textWrap == TextWrap::Wrap);
    return textBlock;
}

std::string TextBlock::Serialize()
{
    Json::Value json;

    TextBlock* obj = this;

    // append base class card element stuff
    json.append(Json::Value(CardElementTypeToString(obj->GetElementType())));
    json.append(Json::Value(obj->GetSpeak()));
    json.append(Json::Value(HorizontalAlignmentToString(obj->GetHorizontalAlignment())));
    json.append(Json::Value(SizeToString(obj->GetSize())));

    // append derived class stuff
    json.append(Json::Value(TextSizeToString(obj->GetTextSize())));
    json.append(Json::Value(TextColorToString(obj->GetTextColor())));
    json.append(Json::Value(TextWeightToString(obj->GetTextWeight())));
    json.append(Json::Value(TextWrapToString(obj->GetWrap() ==  true ? TextWrap::Wrap : TextWrap::NoWrap)));

    Json::FastWriter fastWriter;
    std::string output = fastWriter.write(json);
    return output;
}

std::string TextBlock::GetText() const
{
    return m_text;
}

void TextBlock::SetText(const std::string value)
{
    m_text = value;
}

TextSize TextBlock::GetTextSize() const
{
    return m_textSize;
}

void TextBlock::SetTextSize(const TextSize value)
{
    m_textSize = value;
}

TextWeight TextBlock::GetTextWeight() const
{
    return m_textWeight;
}

void TextBlock::SetTextWeight(const TextWeight value)
{
    m_textWeight = value;
}

TextColor TextBlock::GetTextColor() const
{
    return m_textColor;
}

void TextBlock::SetTextColor(const TextColor value)
{
    m_textColor = value;
}

bool TextBlock::GetWrap() const
{
    return m_wrap;
}

void TextBlock::SetWrap(const bool value)
{
    m_wrap = value;
}

bool TextBlock::GetIsSubtle() const
{
    return m_isSubtle;
}

void TextBlock::SetIsSubtle(const bool value)
{
    m_isSubtle = value;
}