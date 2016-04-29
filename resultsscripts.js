function initialize() {
  var mapOptions = {
    zoom: 11,
    center: new google.maps.LatLng(-27.38123113, 153.0436597)
  }
  var map = new google.maps.Map(document.getElementById("resultsgooglemap"), mapOptions);
  var marker;

  var latitude = getLatitude();
  var longitude = getLongitude();

  for (var i = 0; i < latitude.length; i++) {
    marker = new google.maps.Marker({
    position: new google.maps.LatLng(latitude[i], longitude[i]),
    map: map, title: 'Dog Park'});

  }
}

function getLatitude() {
  var latitude = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    latitude.push(row.cells[4].innerHTML);
   }
   return latitude;
}

function getLongitude() {
  var longitude = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    longitude.push(row.cells[5].innerHTML);
  }
  return longitude;
}


function loadScript() {
  var script = document.createElement("script");
  script.type = "text/javascript";
  script.src = "http://maps.googleapis.com/maps/api/js?key=AIzaSyDYduLoGeuBaC8Cc0fOPMXOBBljvQkxHFk&callback=initialize";
  document.body.appendChild(script);
}

window.onload = loadScript;