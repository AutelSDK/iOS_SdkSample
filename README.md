Add callback for each frame of video decoding result：

```
VideoStreamPlayManager.sharedInstance().insertNewFrameHandler = { [weak self] frame  in
    DispatchQueue.main.async {
        self?.view.makeToast("insertNewFrameHandler  width: \(frame.width)  height: \(frame.height) timeStamp: \(frame.timeStamp)")
    }
    
}
```
