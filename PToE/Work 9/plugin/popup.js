function getCurrentTabUrl(callback) {

  var queryInfo = {
    active: true,
    currentWindow: true
  };

  chrome.tabs.query(queryInfo, (tabs) => {
    var tab = tabs[0];
    var url = tab.url;
    console.assert(typeof url == 'string', 'tab.url should be a string');

    callback(url);
  });
}

function changeImagesOpasity(opacity) {

  var script = 'for(i=0;i<document.images.length;i++)document.images[i].style.opacity='+opacity+';';

  chrome.tabs.executeScript({
    code: script
  });
}

function hightlightUrls(value) {
  var color = 'transparent'; 
  
  if(value)
    color = 'yellow'; 

  var script = 'for(i=0;i<document.links.length;i++)document.links[i].style.backgroundColor="' +color+ ' ";';

  chrome.tabs.executeScript({
    code: script
  });
}

document.addEventListener('DOMContentLoaded', () => {
  getCurrentTabUrl((url) => {
    var dropdown = document.getElementById('dropdown');
    var checkbox = document.getElementById('highlightCheckBox');

    dropdown.value = 0.5;
    checkbox.checked = true;
    changeImagesOpasity(dropdown.value);
    hightlightUrls(true);

    // Ensure the background color is changed and saved when the dropdown
    // selection changes.
    dropdown.addEventListener('change', () => {
      changeImagesOpasity(dropdown.value);
    });

    checkbox.addEventListener('change', () => {
      hightlightUrls(checkbox.checked);
    });


    chrome.tabs.executeScript({
        code: 'document.links.length;'
    },receiveLinks);

  });
});

function receiveLinks(links) {
    document.getElementById("checkboxText").textContent = "Highlight " + links + " Urls";   
}