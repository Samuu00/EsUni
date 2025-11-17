import { Component, signal } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import {MioC} from './mio-c/mio-c';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, MioC],
  templateUrl: './app.html',
  styleUrl: './app.css'
})
export class App {
  protected readonly title = signal('angularExample');
}
