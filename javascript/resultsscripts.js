/*
 function that initialises the Google Map and it's required objects such as map markers
 */
function initialize() {
  // create map object
  var mapOptions = {
    zoom: 11
  }
  var map = new google.maps.Map(document.getElementById("resultsgooglemap"), mapOptions);
  var marker;

  // fetch parameters
  var latitude = getLatitude();
  var longitude = getLongitude();
  var name = getName();
  var id = getID();

  var labels = 1;

  // create bounds to auto-center map on markers
  var infowindow = new google.maps.InfoWindow();
  var bounds = new google.maps.LatLngBounds();

  // plot all markers from the results table, each array is of the same length and
  // contains a value for each marker
  for (var i = 0; i < latitude.length; i++) {
    marker = new google.maps.Marker({
    position: new google.maps.LatLng(latitude[i], longitude[i]),
      map: map,
      label: labels.toString(),
      title: 'Dog Park'
    });

    // extend bounds
    bounds.extend(marker.position);

    // add listener
    google.maps.event.addListener(marker, 'click', (function (marker, i) {
      return function () {
        infowindow.setContent(name[i]);
        infowindow.open(map, marker);
      }
    })(marker, i));

    labels++;

  }

  // fit map on bounds
  map.fitBounds(bounds);

  // add listener
  var listener = google.maps.event.addListener(map, "idle", function () {
    map.setZoom(14);
    google.maps.event.removeListener(listener);
  });

}

/*
 fetch all latitudes present in results and return containing array
 */
function getLatitude() {
  var latitude = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    latitude.push(row.cells[5].innerHTML);
   }
   return latitude;
}

/*
 fetch all longitudes present in results and return containing array
 */
function getName() {
  var name = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    name.push(row.cells[1].innerHTML);
  }
  return name;
}

/*
 fetch id's of park and return containing array
 */
function getID() {
  var id = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    id.push(row.cells[0].innerHTML);
  }
  return id;
}

/*
 fetch all longitudes present in results and return containing array
 */
function getLongitude() {
  var longitude = [];
  var table = document.getElementById("tableresults");
  for (var i = 1, row; row = table.rows[i]; i++) {
    longitude.push(row.cells[6].innerHTML);
  }
  return longitude;
}

/*
 load script
 */
function loadScript() {
  var script = document.createElement("script");
  script.type = "text/javascript";
  script.src = "http://maps.googleapis.com/maps/api/js?key=AIzaSyDYduLoGeuBaC8Cc0fOPMXOBBljvQkxHFk&callback=initialize";
  document.body.appendChild(script);
}

window.onload = loadScript;