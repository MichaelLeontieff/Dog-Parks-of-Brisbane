function initialize() {
  var mapOptions = {
    zoom: 11,
    center: new google.maps.LatLng(-27.38123113, 153.0436597)
  }
  var map = new google.maps.Map(document.getElementById("resultsgooglemap"), mapOptions);
  var marker;

  var latitude = getLatitude();
  var longitude = getLongitude();
  var name = getName();
  var id = getID();

  var labels = 1;

  var infowindow = new google.maps.InfoWindow();
  var bounds = new google.maps.LatLngBounds();

  for (var i = 0; i < latitude.length; i++) {
    marker = new google.maps.Marker({
    position: new google.maps.LatLng(latitude[i], longitude[i]),
      map: map,
      label: labels.toString(),
      title: 'Dog Park'
    });

    bounds.extend(marker.position);

    google.maps.event.addListener(marker, 'click', (function (marker, i) {
      return function () {
        infowindow.setContent(name[i]);
        infowindow.open(map, marker);
      }
    })(marker, i));

    labels++;

  }

  map.fitBounds(bounds);

  var listener = google.maps.event.addListener(map, "idle", function () {
    map.setZoom(14);
    google.maps.event.removeListener(listener);
  });

}

function getLatitude() {
  var latitude = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    latitude.push(row.cells[5].innerHTML);
   }
   return latitude;
}

function getName() {
  var name = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    name.push(row.cells[1].innerHTML);
  }
  return name;
}

function getID() {
  var id = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    id.push(row.cells[0].innerHTML);
  }
  return id;
}

function getLongitude() {
  var longitude = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    longitude.push(row.cells[6].innerHTML);
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