const map = L.map('map').setView([11.0197, -74.8682], 13);
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
    attribution: '&copy; OpenStreetMap contributors',
}).addTo(map);

let startMarker, endMarker, routeLayer;

document.getElementById('coordinate-form').addEventListener('submit', async (e) => {
    e.preventDefault();

    const startLat = parseFloat(document.getElementById('start-lat').value);
    const startLng = parseFloat(document.getElementById('start-lng').value);
    const endLat = parseFloat(document.getElementById('end-lat').value);
    const endLng = parseFloat(document.getElementById('end-lng').value);

    if (startMarker) map.removeLayer(startMarker);
    if (endMarker) map.removeLayer(endMarker);
    if (routeLayer) map.removeLayer(routeLayer);

    startMarker = L.marker([startLat, startLng]).addTo(map);
    endMarker = L.marker([endLat, endLng]).addTo(map);

    map.fitBounds(L.latLngBounds([startLat, startLng], [endLat, endLng]));

    try {
        //const response = await fetch(`http://localhost:5000/route/v1/driving/${startLng},${startLat};${endLng},${endLat}?overview=full`);
        const response = await fetch(`http://router.project-osrm.org/route/v1/driving/${startLng},${startLat};${endLng},${endLat}?overview=full`);
        const data = await response.json();

        if (data.code === 'Ok') {
            const distance = data.routes[0].distance;
            document.getElementById('distance-value').textContent = distance.toFixed(2);

            const routeCoordinates = polyline.decode(data.routes[0].geometry);
            routeLayer = L.polyline(routeCoordinates.map(([lat, lng]) => [lat, lng]), { color: 'blue' }).addTo(map);
        } else {
            alert('Error fetching route data.');
        }
    } catch (err) {
        console.error(err);
        alert('An error occurred while calculating the distance.');
    }
});