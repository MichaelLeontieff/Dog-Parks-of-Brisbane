
function initialize() {
  var mapOptions = {
    zoom: 15,
    center: new google.maps.LatLng(-27.38123113, 153.0436597)
  }
  var map = new google.maps.Map(document.getElementById("locationmap"), mapOptions);

  var marker = new google.maps.Marker({
    position: new google.maps.LatLng(-27.38123113, 153.0436597),
    map: map,
    title: 'Dog Park'
  });
}

function loadScript() {
  var script = document.createElement("script");
  script.type = "text/javascript";
  script.src = "http://maps.googleapis.com/maps/api/js?key=AIzaSyDYduLoGeuBaC8Cc0fOPMXOBBljvQkxHFk&callback=initialize";
  document.body.appendChild(script);
}

window.onload = loadScript;
