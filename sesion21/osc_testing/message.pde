class MessageReceived {
  String _msg;
  color _color;
  PVector _pos;
  int _start_time;
  
  MessageReceived(String msg, color c, PVector pos)
  {
    _msg = msg;
    _color = c;
    _pos = pos;
    _start_time = millis();
  }

  boolean Remove() {
    return _pos.y > height;
      //return (millis() - _start_time) > 5000;
  }
  
  void Draw(){
    pushMatrix();
    textSize(32);
    translate(_pos.x,_pos.y);
    fill(_color);
    text(_msg,0,0);
    popMatrix();
    _pos.y+=1.0;
  }
}
