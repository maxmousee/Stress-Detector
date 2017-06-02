sudo apt-get install python-pip;
sudo apt-get install python-numpy python-scipy python-matplotlib ipython ipython-notebook python-pandas python-sympy python-nose;
sudo apt-get install git;
sudo apt-get install curl;
sudo easy_install web.py;
cd ~/;
mkdir repo;
cd repo;
git clone https://github.com/maxmousee/Stress-Detector.git -b master
#on terminal: sh install_py_depedencies_debian.sh
#need to change this
#to run it just go to the folder and type "python StressDetector.py" without the quotes
#it will run as a http service listening to port 8080
#to send a test request just run "curl -H "Content-Type: application/json" --data @audiodata.json http://localhost:8080/processAudio"
