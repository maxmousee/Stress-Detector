##Stress Detector Python WebService

To run it just go to the folder and type "python StressDetector.py" without the quotes
It will run as a http service listening to port 8080

To send a test request just run "curl -H "Content-Type: application/json" --data @audiodata.json http://localhost:8080/processAudio"