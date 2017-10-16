﻿using System.Windows;
using System.Windows.Controls;

#if WPF

#elif XAMARIN
using FrameworkElement = Xamarin.Forms.View;
using Xamarin.Forms;
using CheckBox = Xamarin.Forms.Switch;
#endif

namespace AdaptiveCards.Rendering.Wpf
{
    public static class XamlToggleInput
    {
        public static FrameworkElement Render(AdaptiveToggleInput input, RenderContext context)
        {
            if (context.Config.SupportsInteractivity)
            {
                var uiToggle = new CheckBox();
#if WPF
                // TODO: Finish switch
                uiToggle.Content = input.Title;
#endif
                uiToggle.SetState(input.Value == (input.ValueOn ?? "true"));
                uiToggle.Style = context.GetStyle($"Adaptive.Input.Toggle");
                uiToggle.SetContext(input);
                context.InputBindings.Add(input.Id, () =>
                {
                    return uiToggle.GetState() == true ? input.ValueOn ?? "true" : input.ValueOff ?? "false";
                });
                return uiToggle;
            }
            else
            {
                AdaptiveContainer container = AdaptiveTypedElementConverter.CreateElement<AdaptiveContainer>();
                container.Separation = input.Separation;

                AdaptiveTextBlock textBlock = AdaptiveTypedElementConverter.CreateElement<AdaptiveTextBlock>();
                textBlock.Text = XamlUtilities.GetFallbackText(input);
                container.Items.Add(textBlock);
                if (input.Value != null)
                {
                    textBlock = AdaptiveTypedElementConverter.CreateElement<AdaptiveTextBlock>();
                    textBlock.Text = (input.Value == (input.ValueOn ?? "true")) ? input.ValueOn ?? "selected" : input.ValueOff ?? "not selected";
                    textBlock.Color = AdaptiveTextColor.Accent;
                    textBlock.Wrap = true;
                    container.Items.Add(textBlock);
                }
                return context.Render(container);
            }

        }
    }

}