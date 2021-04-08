time -p {
  cd ./
  # If you want a clean compilation uncomment the next 2 commands
  find . -name '*.o' -exec rm {} \;
  find . -name 'moc*' -exec rm {} \;
  if qmake; then
      if make; then
        wait
      else
        echo ERROR
      fi
  else
      echo ERROR
    fi
}