// Initialize map
const map = L.map('map').setView([-34.184256, -70.746800], 13);

// Load map tiles
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    maxZoom: 19,
}).addTo(map);

// Add marker group
const markers = L.layerGroup().addTo(map);

// Fetch JSON and calculate routes
document.getElementById('calculate-distance').addEventListener('click', async () => {
    try {
        // Fetch the JSON file
        const response = await fetch('coordinates.json');
        const data = await response.json();

        // Validate data
        if (!Array.isArray(data) || data.length < 2) {
            alert('Invalid data: At least two points are required to calculate routes.');
            return;
        }

        // Clear existing markers and routes
        markers.clearLayers();

        let totalDistance = 0; // To accumulate total distance

        // Iterate through consecutive points to calculate each route
        for (let i = 0; i < data.length - 1; i++) {
            const start = data[i];
            const end = data[i + 1];

            // Add markers for each coordinate
            L.marker([start[0], start[1]])
                .addTo(markers)
                .bindPopup(`Start Point ${i + 1} ${start[1]},${start[0]}`)
                .openPopup();

            L.marker([end[0], end[1]])
                .addTo(markers)
                .bindPopup(`End Point ${i + 2} ${end[1]},${end[0]}`)
                .openPopup();

            // Fetch route data from OSRM
            const osrmUrl = `http://localhost:5000/route/v1/driving/${start[1]},${start[0]};${end[1]},${end[0]}?overview=full&geometries=polyline`;
            const osrmResponse = await fetch(osrmUrl);
            const osrmData = await osrmResponse.json();

            if (osrmData.routes && osrmData.routes.length > 0) {
                const route = osrmData.routes[0];
                totalDistance += route.distance; // Accumulate distance

                // Decode polyline and display the route on the map
                const decodedPolyline = polyline.decode(route.geometry);
                const latLngs = decodedPolyline.map(([lat, lng]) => [lat, lng]);
                const line = L.polyline(latLngs, { color: 'blue' });
                line.addTo(map);
            }
        }

        // Update total distance in the UI
        document.getElementById('distance-value').textContent = totalDistance.toFixed(2);
        console.log(`Total distance: ${totalDistance.toFixed(2)} meters`);
    } catch (error) {
        console.error('Error calculating route:', error);
        alert('Failed to calculate route.');
    }
});
