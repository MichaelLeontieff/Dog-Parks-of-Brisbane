function getLocation() {
	if (navigator.geolocation) {
		navigator.geolocation.getCurrentPosition(showPosition, showError);
	} else {
		document.getElementById("geolocationstatus").innerHTML="Error!";
	}
}

function showPosition(position) {

	// distance calc //
	var lat1 = position.coords.latitude;
	var lon1 = position.coords.longitude;

	console.log("lat1 " + lat1);
	console.log("lon1 " + lon1);

	document.getElementById("geolocationstatus").innerHTML = "Latitude: " + lat1 + "\nLongitude: " + lon1;

}
	

function showError(error) {
	var msg = "";
	switch(error.code) {
		case error.PERMISSION_DENIED:
			msg = "User denied the request for Geolocation."
			break;
		case error.POSITION_UNAVAILABLE:
			msg = "Location information is unavailable."
			break;
		case error.TIMEOUT:
			msg = "The request to get user location timed out."
			break;
		case error.UNKNOWN_ERROR:
			msg = "An unknown error occurred."
			break;
	}
	document.getElementById("status").innerHTML = msg;
}