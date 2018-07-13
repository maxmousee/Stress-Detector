#!/usr/bin/env bash

python StressDetectorWS.py & sleep 5; curl -H "Content-Type: application/json" --data @audiodata.json http://localhost:8080/processAudio;
kill $!;