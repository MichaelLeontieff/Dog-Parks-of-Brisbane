/*
Initialise map object and marker corresponding to lat lon of park
 */

/*
 function to extract parknames from rendered parkinfotable
 used to create named map markers for the google map
 */
function getName() {
    var refTab = document.getElementById("parkinfotable")
    for (var i = 0; row = refTab.rows[i]; i++) {
        row = refTab.rows[i];
        for (var j = 0; col = row.cells[j]; j++) {
            if (i == 6 && j == 1) {
                console.log("name: " + col.firstChild.nodeValue);
                return col.firstChild.nodeValue;
            }
        }
    }
}

/*
 function to extract latitude from rendered parkinfotable
 */
function getLatitude() {
    var refTab = document.getElementById("parkinfotable")
    for (var i = 0; row = refTab.rows[i]; i++) {
        row = refTab.rows[i];
        for (var j = 0; col = row.cells[j]; j++) {
            if (i == 8 && j == 1) {
                console.log("lat: " + col.firstChild.nodeValue);
                return col.firstChild.nodeValue;
            }
        }
    }
}

/*
 function to extract longitude from rendered parkinfotable
 */
function getLongitude() {
    var refTab = document.getElementById("parkinfotable")
    for (var i = 0; row = refTab.rows[i]; i++) {
        row = refTab.rows[i];
        for (var j = 0; col = row.cells[j]; j++) {
            if (i == 9 && j == 1) {
                console.log("lon: " + col.firstChild.nodeValue);
                return col.firstChild.nodeValue;
            }
        }
    }
}

/*
 function that initialises the Google Map and it's required objects such as map markers
 */
function initialize() {
    // create map object
    var mapOptions = {
        zoom: 17
    }
    var map = new google.maps.Map(document.getElementById("locationmap"), mapOptions);
    var marker;

    // fetch parameters
    var latitude = getLatitude();
    var longitude = getLongitude();
    var name = getName();

    // set bounds to auto-centre the map around markers
    var infowindow = new google.maps.InfoWindow();
    var bounds = new google.maps.LatLngBounds();

    // create single marker to plot
    marker = new google.maps.Marker({
        position: new google.maps.LatLng(latitude, longitude),
        map: map,
        title: 'Dog Park'
    });

    // extend bounds to account for previously created marker
    bounds.extend(marker.position);

    // add click listener
    google.maps.event.addListener(marker, 'click', (function (marker) {
        return function () {
            infowindow.setContent(name);
            infowindow.open(map, marker);
        }
    })(marker));

    // fit map according to bounds
    map.fitBounds(bounds);

    // initialise listener
    var listener = google.maps.event.addListener(map, "idle", function () {
        map.setZoom(17);
        google.maps.event.removeListener(listener);
    });

}

/*
 Load script and api
 */
function loadScript() {
    var script = document.createElement("script");
    script.type = "text/javascript";
    script.src = "http://maps.googleapis.com/maps/api/js?key=AIzaSyDYduLoGeuBaC8Cc0fOPMXOBBljvQkxHFk&callback=initialize";
    document.body.appendChild(script);
}

/*
Run when page loads
 */
window.onload = loadScript;
