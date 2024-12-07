#include <iostream>

//Target
class MP3Player {
    public:
      virtual void playMP3(const std::string& filename) const {
        std::cout << "Playing MP3 file: " << filename << std::endl;
      }
      virtual ~MP3Player() = default;
};

//Adaptee
class MP4Player {
    public:
      void playMP4(const std::string& filename) const {
        std::cout << "Playing MP4 file: " << filename << std::endl;
      }
};

//Adapter
class MediaAdapter : public MP3Player {
    private:
      MP4Player* m_player;
    public:
      MediaAdapter(MP4Player* player) : m_player(player) {}
      void playMP3(const std::string& filename) const override {
        if(filename.find(".mp4") != std::string::npos) {
            m_player->playMP4(filename);
        }
        else {
            std::cout << "Invalid filename." << std::endl;
        }
      }
};

int main() {
    MP4Player* mp4Player = new MP4Player();
    MediaAdapter* adapter = new MediaAdapter(mp4Player);
    adapter->playMP3("serial.mp4");
    mp4Player->playMP4("movie.mp4");
    MP3Player* mp3Player = new MP3Player;
    mp3Player->playMP3("song.mp3");
    delete mp4Player;
    delete mp3Player;
    delete adapter;
}