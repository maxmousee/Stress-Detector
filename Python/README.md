## Stress Detector Python WebService

To run it just go to the folder and type "python StressDetectorWS.py" without the quotes
It will run as a http service listening to port 8080

To send a test request just run "curl -H "Content-Type: application/json" --data @audiodata.json http://localhost:8080/processAudio"

## Stress Detector Python Desktop

To run it just go to the folder and type "python StressDetectorDesktop.py" without the quotes
It will verify stress level for "rain_man_driver_8000.wav". Feel free to change the code to check for other files.
It should print the graph of the stress data as well.
