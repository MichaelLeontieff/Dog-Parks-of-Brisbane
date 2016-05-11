/*
Initialise map object and marker corresponding to lat lon of park
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

// function initialize() {
//
//     var mapOptions = {zoom: 15, center: new google.maps.LatLng(-27.38123113, 153.0436597)};
//
//     var map = new google.maps.Map(document.getElementById("locationmap"), mapOptions);
//
//     var marker;
//
//     marker = new google.maps.Marker({
//         position: new google.maps.LatLng(-27.38123113, 153.0436597), map: map, title: 'Dog Park'
//     });
// }

function initialize() {
    var mapOptions = {
        zoom: 17
    }
    var map = new google.maps.Map(document.getElementById("locationmap"), mapOptions);
    var marker;

    var latitude = getLatitude();
    var longitude = getLongitude();
    var name = getName();


    var infowindow = new google.maps.InfoWindow();
    var bounds = new google.maps.LatLngBounds();


    marker = new google.maps.Marker({
        position: new google.maps.LatLng(latitude, longitude),
        map: map,
        title: 'Dog Park'
    });

    bounds.extend(marker.position);

    google.maps.event.addListener(marker, 'click', (function (marker) {
        return function () {
            infowindow.setContent(name);
            infowindow.open(map, marker);
        }
    })(marker));

    map.fitBounds(bounds);

    var listener = google.maps.event.addListener(map, "idle", function () {
        map.setZoom(17);
        google.maps.event.removeListener(listener);
    });

}

/*
Load script
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
