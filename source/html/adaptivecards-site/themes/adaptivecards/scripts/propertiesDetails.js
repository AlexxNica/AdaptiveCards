"use strict";

var markedschema = require("marked-schema");
var marked = require("marked");
var fs = require("fs");

hexo.extend.helper.register('propertiesDetails', function (properties) {
  var html = '<h2 class="w3-container">Properties</h2>';

  for (var name in properties) {
    if (properties.hasOwnProperty(name)) {
      var property = properties[name];

      // Get the markdown for the property and turn it into HTML
      html += '<div class="w3-container">';
    
      html += marked(markedschema.generateMarkdown.createPropertyDetails(property, 3), { headerPrefix: "dedupe-header" });
      html += '</div>'


      // Load card example file into a div, using JS to render it later
      property.examples.forEach(function (example, i) {
        if (i === 0) {
          html += '<h3 class="w3-container">Example</h3>';
        }

        var exampleContent = fs.readFileSync(example, "utf8");

        html += '<div class="w3-cell-row">';

        html += '<div class="w3-container w3-cell w3-mobile code-snippet">';
        html += "<pre><code class='json'>" + exampleContent + "</code></pre>";
        html += "</div>";

        html += '<div class="w3-container w3-cell w3-mobile" style="width: 300px">';
        html += '<div class="adaptivecard">' + exampleContent + '</div>';
        html += '<a class="w3-btn w3-blue" target="_blank" href="/visualizer?card=/explorer/cards/TextBlock.Color.json">Try it Yourself »</a>';
        html += '</div>';

        html += '</div>'; // w3-cell-row

      });

    }
  }

  return html;
});