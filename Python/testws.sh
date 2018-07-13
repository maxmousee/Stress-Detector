#!/usr/bin/env bash

python Python/StressDetectorWS.py & sleep 5; curl -H "Content-Type: application/json" --data @Python/audiodata.json http://localhost:8080/processAudio;
kill $!;
cd ..;